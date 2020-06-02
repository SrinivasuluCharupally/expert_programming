#include<iostream>
using namespace std;

class X {
int i;
public: X():i(true) {}
~X () { cout << i << endl; } 
};

int main() {
X a;
}

