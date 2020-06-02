// check the env is set or not, then procced

#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
//	int var;
//	var = os::GetEnvVar("LD_LIBRARY_PATH");
//	os::GetEnvVar("HSA_ENABLE_THREAD_TRACE");
	char* var = getenv("LD_LIBRARY_PATH");
	char* var_path = getenv("PATH");
	cout << var << endl;
	cout << var_path << endl;
	bool var_bool = getenv("HSA_LIB");
	cout << "bool HSA_LIB = " << var_bool << endl;

}
