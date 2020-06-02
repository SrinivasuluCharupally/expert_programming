//Friend Class A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class.


// Friend Function Like friend class, a friend function can be given special grant to access private and protected members. A friend function can be:


// source http://www.geeksforgeeks.org/friend-class-function-cpp/
#include<iostream>
using namespace std;

class base {
  private: int pri;
  protected: int pro;
  public: int pub;
  base() : pri(0), pro(1), pub(2) { }
 void friend friend_func();
};

void friend_func() {
	base b;
	cout << "access base private from friend = " << b.pri << endl;
        cout << "access base protected from friend = " << b.pro << endl;
}

void func() {
        base b;
//        cout << "access base private from friend = " << b.pri << endl;
//        cout << "access base protected from friend = " << b.pro << endl;
        cout << "access base public from func() though it's not friend so you cant access private & protected = " << b.pub << endl;

}

int main() {

	friend_func();
	func(); // you cant access base private & public from here beceause it's not friend of base
}
