#include<iostream>
using namespace std;

class X {
public: int a, b, c;
void print() const {
cout << a << endl << b << endl << c << endl;
}
};

int main() {
X x, *y = &x;
int X::*p =  &X::a;
y->*p = 50;
p = &X::b;
x.*p = 52;
p = &X::c;
y->*p = 54;
y->print();
}
