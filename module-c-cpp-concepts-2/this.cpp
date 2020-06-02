#include<iostream>
using namespace std;

class base {
	int i;
public:
	base() : i(0) {
                cout << "constructor address = " << this << endl;
	}
	void setval(int val) {
		this->i = val;
                cout << "setval address = " << this << endl;

	}
	int getval() {
		cout << "getval address = " << this << endl;
		return i;
	}
};

int main() {
	base b;
	b.setval(100);
	cout << "value = " << b.getval() << endl;
}
