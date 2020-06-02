/// @brief: this tests the use of explicity specifier... it is more usefull when there is only one parameter for constructor....

/// @brief: this is mainly to avoid compiler casting to differnt datatype..


/// source http://www.cplusplus.com/forum/general/168292/

#include<iostream>
using namespace std;

class A {
public:
	int i;
  public:
	A(int value) : i(value) {} 
};


void func_implicit(A obj) { 
	cout << "A::value = " << obj.i <<  " implicit convertion " << endl;
}

class B {
public: 
	int i;
        explicit B(int value) : i(value) {}
};

void func_explicit(B obj) {
        cout << "B::value = " << obj.i << " explicity conversion" << endl;
}

int main() {
	func_implicit(200);  // func should accept only class A obj but complier does the casting...  it's not good...

	func_explicit(B(200)); // func_explicit(200) will give compiler error becease casting disabled
}
