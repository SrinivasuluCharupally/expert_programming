#include<iostream>
#include<dlfcn.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
char *error;
	std::cout << "Openning so file" << std::endl;
	void *handle = dlopen("./so-file.so", RTLD_LAZY);
	if(!handle) { std::cout << "Failed to open so file" << std::endl; return 0; }
	std::cout << "Calling welcom from so file" << std::endl;
	typedef void (*welcom_t)();
	welcom_t welcom = (welcom_t)dlsym(handle, "welcom");
        if ((error = dlerror()) != NULL)  {
            fputs(error, stderr); 
	    std::cout << std::endl;
            exit(1);
        }
	typedef int (*max_t)(int,int);
	max_t max = (max_t)dlsym(handle, "max");
	std::cout << "Max of 10,20 = " << max(10,20) << std::endl;
	std::cout << "Loaded welcom from so file" << std::endl;
	welcom();
	std::cout << "Executed welcom from so file" << std::endl;
	dlclose(handle);
}
