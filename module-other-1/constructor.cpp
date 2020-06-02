#include<iostream>
using namespace std;

class X {
int i;
public: X() ;
};

X::X() {
cout << "constructor executed" << endl;
}

int main() {
X a;
}

