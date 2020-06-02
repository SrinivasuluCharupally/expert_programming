// try catch example

/// @Brief source http://www.geeksforgeeks.org/exception-handling-c/

#include<iostream>
using namespace std;


int func() {
	throw 10;
}

int main() {
	try {
		func();
	}
	catch(int k) {
		cout << "integer exception" << endl;
	}
	catch(char c) {
		cout << "char exception" << endl;
	}

}
