#include<iostream>
using namespace std;

struct A {
private: int i; //
public: void f(); // default access is public
};

void A::f() {
i = 10;
}

class B {
int j; // default access is private in class
public: void g();
};

void B::g() {
j = 20;
}

int main() {
struct A a; a.f();
class B b; b.g();
}
