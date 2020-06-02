#include <stdlib.h>
#include <string.h>

int compare_cstr(const void* c1, const void* c2) 
{ 
   return strcmp(*(const char**)(c1), *(const char**)(c2)); 
}

int main() {

   const char* obj[4] = {"fine", "ppoq", "tri", "get"};
   qsort(obj, 4, sizeof(obj[0]), compare_cstr);
   std::copy(obj, obj + 4, std::ostream_iterator<const char*>(std::cout, "\n"));
}
