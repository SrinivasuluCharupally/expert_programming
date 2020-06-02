// threads basic
// source https://stackoverflow.com/questions/17274032/c-threads-stdsystem-error-operation-not-permitted

// source code http://www.cplusplus.com/reference/thread/thread/

// compiler using "g++ threads_simple_one.cpp -o threads_simple_one -std=c++11 -pthread "

#include<iostream>
#include<thread>
using namespace std;

int x = 10;

void first_fun() {
	cout << "base " << x << endl;
}


void second_fun(int k) {
	cout << "second " << x+k << endl;
}

int main() {
	thread first(first_fun);
	thread second(second_fun, 20);

	first.join();
	second.join();
}
