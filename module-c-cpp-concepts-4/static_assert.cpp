/// @brief static assert example.. the static assertion failes at compile time rather than runtime.
// The regular assert fails at runtime...

/// source https://stackoverflow.com/questions/1647895/what-does-static-assert-do-and-what-would-you-use-it-for
 

// compiler : --std=c++11

#include<iostream>
#include<assert.h>
using namespace std;

int main() {
	assert(10 == 10); // it's regular assert, does not take any string value, fails at runtime

assert(false && "Can't release imported memory with free.");

	const int i = 11; // compiler failure, no issue if i = 11...
	static_assert(i == 11 , "Value matched"); // it fails at compile time, not even allowed to compile the program if condition failed
}
