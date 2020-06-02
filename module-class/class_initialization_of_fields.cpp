#include<iostream>
using namespace std;

class X {
int i;
public: X(int x);
};

X::X(int x) : i(x) {
cout << i << endl;
}

int main() {
X a(10);
}

