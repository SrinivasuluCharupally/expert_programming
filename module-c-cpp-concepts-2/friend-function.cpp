#include<iostream>
using namespace std;

class base {
	int i;
public:
	base() : i(0) { }
	friend void setvalue(base b, int val);
};

void setvalue(base b, int val) {
	b.i = val;
}

int main() {
base b;
setvalue(b,20);
}
