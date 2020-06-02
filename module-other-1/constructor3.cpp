#include<iostream>
using namespace std;

class A {
public:  A() { cout << "A constructor" << endl; }
};

class B : public A {
public : B() { cout << "B construcotor" << endl; }
};

int main() {
A* a = new B;
B b;
//B* b = dynamic_cast<A*>(a);
}
