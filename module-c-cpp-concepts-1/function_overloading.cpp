#include<iostream>
using namespace std;

class X {
int i;
public:
	X();
	X(int x);
};

X::X() {
cout << "constructor without inputs" << endl;
}

X::X(int x) {
cout << " constructor with one intput " << endl;
}

int main() {
X a;
X b(1);
}
