#include<iostream>
#include<dlfcn.h>
#include<stdlib.h>
#include "max_intercepter.h"
using namespace std;

handle open_handle() {
	handle handle_ = dlopen("./libmax_library.so", RTLD_LAZY);

	if(!handle_) cout << "Fail to open library ..." << endl;
	return handle_;
}



extern "C" int max(int a, int b) { // it should match with max_library.so, because it's extern "c", otherwise it will not link..

	cout << "     Hook enabled ... call back func inprogress.." << endl;
	handle handle_ = open_handle();
	max_t max_wrapper = (max_t)dlsym(handle_, "max");
	cout << "     Func => max(" << a << " ," << b << ")" ;
	cout << " = " << "SUCCESS";
	int res =  max_wrapper(a,b);
	cout << " (" << res << ")" << endl;
	return res;
}

//int main() {
//	max(10,20);
//}




