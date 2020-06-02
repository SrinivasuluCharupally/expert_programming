// calling a funtion from a constructor using member function initiallization..

// source : example

#include<iostream>
using namespace std;
/*
void func() {
	cout << "I am func called from base constructor member initialization ... " << endl;
}
*/

class base {
	int k;
public:
	base(): k(func()) { func(); }  // but base() : func() { } will not work as : is used to initalize member fields to return of func() should be assigned to some member...
public:
	int func() {
	        cout << "I am func called from base constructor member initialization ... " << endl;
		return 10;
	}
};

int main() {
	base b;
}
	

