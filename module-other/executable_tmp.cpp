hsa_status_t AmdGpuImage::IterateSymbols(hsa_code_object_t code_object,
                                         hsa_status_t (*callback)(
                                           hsa_code_object_t code_object,
                                           hsa_code_symbol_t symbol,
                                           void* data),
                                         void* data) {
  assert(callback);

  void *amdgpumi = reinterpret_cast<void*>(code_object.handle);
  if (!amdgpumi) {
    return HSA_STATUS_ERROR_INVALID_CODE_OBJECT;
  }
  if (!core::loader::ElfMemoryImage::Is64(amdgpumi)) {
    return HSA_STATUS_ERROR_INVALID_CODE_OBJECT;
  }
  if (!core::loader::ElfMemoryImage::IsAmdGpu(amdgpumi)) {
    return HSA_STATUS_ERROR_INVALID_CODE_OBJECT;
  }

  uint64_t amdgpumisz = ElfMemoryImage::Size(amdgpumi);
  if (!amdgpumisz) {
    return HSA_STATUS_ERROR_INVALID_CODE_OBJECT;
  }

  uint16_t symtabSNDX = ElfMemoryImage::FindSNDX(amdgpumi, SHT_SYMTAB);
  if (!symtabSNDX) {
    return HSA_STATUS_ERROR_INVALID_CODE_OBJECT;
  }

  Elf *amdgpuemi = NULL;
  amdgpuemi = elf_memory((char*)amdgpumi, size_t(amdgpumisz));
  assert(amdgpuemi);

  Elf_Scn *symtabSCN = NULL;
  symtabSCN = elf_getscn(amdgpuemi, size_t(symtabSNDX));
  assert(symtabSCN);

  Elf64_Shdr *symtabSHDR = NULL;
  symtabSHDR = elf64_getshdr(symtabSCN);
  assert(symtabSHDR);

  uint32_t strtabSNDX = symtabSHDR->sh_link;
  assert(strtabSNDX);

  Elf_Data *symtabDAT = NULL;
  symtabDAT = elf_getdata(symtabSCN, symtabDAT);
  assert(symtabDAT);

  Elf64_Sym *rawDAT = (Elf64_Sym*)symtabDAT->d_buf;
  assert(rawDAT);
  size_t rawSZ = symtabDAT->d_size;
  assert(rawSZ);
  assert(!(rawSZ % sizeof(Elf64_Sym)));

  auto symbol_entry = symbols_.find(amdgpumi);
  if (symbol_entry == symbols_.end()) {
    std::vector<Symbol*> *vec =
      new std::vector<Symbol*>(rawSZ / sizeof(Elf64_Sym), NULL);
    symbol_entry = symbols_.insert(std::make_pair(amdgpumi, vec)).first;
    //delete(vec);
  }

  for (size_t i = 0; i < rawSZ / sizeof(Elf64_Sym); ++i) {
    hsa_code_symbol_t sym_handle = {0};
    if (symbol_entry->second->at(i)) {
      sym_handle = Symbol::CConvert(symbol_entry->second->at(i));
    } else {
      char *elf_symbol_name =
        elf_strptr(amdgpuemi, strtabSNDX, rawDAT[i].st_name);
      assert(elf_symbol_name);

      std::string mangled_name(elf_symbol_name);

      Elf_Scn *scn = NULL;
      scn = elf_getscn(amdgpuemi, size_t(rawDAT[i].st_shndx));
      assert(scn);
      Elf64_Shdr *shdr = NULL;
      shdr = elf64_getshdr(scn);
      assert(shdr);
      Elf_Data *data = NULL;
      data = elf_getdata(scn, data);
      assert(data);

      Symbol *sym = NULL;
      switch (ELF64_ST_TYPE(rawDAT[i].st_info)) {
        case STT_AMDGPU_HSA_KERNEL: {
          char *text = (char*)data->d_buf;
          assert(text);

          amd_kernel_code_t *akc =
            (amd_kernel_code_t*)(text + rawDAT[i].st_value);
          assert(akc);

          hsa_symbol_linkage_t linkage =
            ELF64_ST_BIND(rawDAT[i].st_info) == STB_GLOBAL ?
              HSA_SYMBOL_LINKAGE_PROGRAM : HSA_SYMBOL_LINKAGE_MODULE;
          bool is_definition = true;
          uint32_t kernarg_segment_size =
            uint32_t(akc->kernarg_segment_byte_size);
          uint32_t kernarg_segment_alignment =
            uint32_t(1 << akc->kernarg_segment_alignment);
          uint32_t group_segment_size =
            uint32_t(akc->workgroup_group_segment_byte_size);
          uint32_t private_segment_size =
            uint32_t(akc->workitem_private_segment_byte_size);
          bool is_dynamic_callstack =
            bool(akc->is_dynamic_callstack);

          sym = new KernelSymbol(false,
                                 mangled_name,
                                 linkage,
                                 is_definition,
                                 kernarg_segment_size,
                                 kernarg_segment_alignment,
                                 group_segment_size,
                                 private_segment_size,
                                 is_dynamic_callstack);
          break;
        }
        case STT_COMMON: {
          hsa_symbol_linkage_t linkage =
            ELF64_ST_BIND(rawDAT[i].st_info) == STB_GLOBAL ?
              HSA_SYMBOL_LINKAGE_PROGRAM : HSA_SYMBOL_LINKAGE_MODULE;
          bool is_definition = false;
          hsa_variable_allocation_t allocation =
            shdr->sh_flags & SHF_AMDGPU_HSA_AGENT ?
              HSA_VARIABLE_ALLOCATION_AGENT : HSA_VARIABLE_ALLOCATION_PROGRAM;
          hsa_variable_segment_t segment =
            shdr->sh_flags & SHF_AMDGPU_HSA_READONLY ?
              HSA_VARIABLE_SEGMENT_READONLY : HSA_VARIABLE_SEGMENT_GLOBAL;
          uint32_t size = uint32_t(rawDAT[i].st_size);
          uint32_t alignment = uint32_t(rawDAT[i].st_value);
          bool is_constant = shdr->sh_flags & SHF_WRITE ? true : false;

          sym = new VariableSymbol(false,
                                   mangled_name,
                                   linkage,
                                   is_definition,
                                   allocation,
                                   segment,
                                   size,
                                   alignment,
                                   is_constant);
          break;
        }
        case STT_OBJECT: {
          hsa_symbol_linkage_t linkage =
            ELF64_ST_BIND(rawDAT[i].st_info) == STB_GLOBAL ?
              HSA_SYMBOL_LINKAGE_PROGRAM : HSA_SYMBOL_LINKAGE_MODULE;
          bool is_definition = true;
          hsa_variable_allocation_t allocation =
            shdr->sh_flags & SHF_AMDGPU_HSA_AGENT ?
              HSA_VARIABLE_ALLOCATION_AGENT : HSA_VARIABLE_ALLOCATION_PROGRAM;
          hsa_variable_segment_t segment =
            shdr->sh_flags & SHF_AMDGPU_HSA_READONLY ?
              HSA_VARIABLE_SEGMENT_READONLY : HSA_VARIABLE_SEGMENT_GLOBAL;
          uint32_t size = uint32_t(rawDAT[i].st_size);
          uint32_t alignment = uint32_t(shdr->sh_addralign);
          bool is_constant = shdr->sh_flags & SHF_WRITE ? true : false;

          sym = new VariableSymbol(false,
                                   mangled_name,
                                   linkage,
                                   is_definition,
                                   allocation,
                                   segment,
                                   size,
                                   alignment,
                                   is_constant);
          break;
        }
        default: {
          break;
        }
      }

      if (sym) {
        assert(!symbol_entry->second->at(i));
        symbol_entry->second->at(i) = sym;
        sym_handle = Symbol::CConvert(symbol_entry->second->at(i));
      }
    }

    if (sym_handle.handle) {
      hsa_status_t hsc = callback(code_object, sym_handle, data);
      if (HSA_STATUS_SUCCESS != hsc) {
        elf_end(amdgpuemi);
        return hsc;
      }
    }
  }

  elf_end(amdgpuemi);
  return HSA_STATUS_SUCCESS;
}
