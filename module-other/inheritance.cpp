#include<iostream>
using namespace std;

class A {
int i;
public: A(int ii) : i(ii) {cout << " A construcotr" << endl; }
~A() {cout << "~A destrucotr" << endl;}
void f() const {cout << "A . f()b " << endl;}
};

class B {
int i;
public : B(int ii) : i(ii) {cout << "B constructor" << endl; }
~B() {cout << "~B destructor " << endl; }
void f()  const {cout << "B . F() " << endl;} 
};

class C : public B {
A a;
public: C(int ii) : B(ii), a(ii) {cout << "C constructor " << endl; }
~C() {cout << " ~C destructor " << endl;}
void f() const { cout << " C . f() " << endl;
	a.f();
        B::f();
}
};

int main() {
C c(47);
}

