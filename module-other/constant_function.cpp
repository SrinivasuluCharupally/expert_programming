#include<iostream>
using namespace std;

class X {
int i;
public: 
X(int k);
int f() const;
};

X::X(int k):i(k) {
}

int X::f() const {
//i++;
cout << i << endl;
}


int main() {
X a(2);
a.f();
const X b(3);
b.f();
}
