#include<iostream>
using namespace std;

class X {
int i;
public: X(int x);
	~X();
};

X::X(int x) { cout << " constructor" << endl; }
X::~X() { cout << "destructor" << endl; }


int main() {
X a[4] = { 3, 4, 5,6};
//X t(3);
}
