// As we knew, pthread return type is void* but want to return different data type , casting might not work all the time in case float is casted to (void*)f then threr is a chance that you loose precision
// below example examplain how

// source - pthread book

#include<iostream>
#include<pthread.h>
using namespace std;

void* ReturnChar(void* ) {
	char* ch = new char[10]; // you have to allocate memory the pass the pointer
//	char charr[] = "hwllow world"; // you can allocate memory on stack then pass address
	for(int i = 0; i < 10; ++i) 
	ch[i] = 'l'; // shore value into memory
//	ch = charr;  // store the stack address
	return ch; // return that memory 
}

int main() {
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, ReturnChar, NULL);
	void* returnvalue; // this is used to store the return pointer
	pthread_join(thread_id, &returnvalue);

	char* returntype = (char*)returnvalue; // this is to convert return to char
	cout << returntype << endl;

}
