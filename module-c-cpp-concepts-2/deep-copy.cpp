#include<iostream>
using namespace std;

class base {
	int* x;
public:
	base(int v) {
		x = new int;
		*x = v;
	}
/*	base(const base& obj) {
		x = new int;
		*x = obj.getval();
	}
*/
	void setval(int v) {
		*x = v;
	}
	int getval() const {
		return *x;
	}
	~base() {
	delete x;
	}
};

int main(int argc, char* argv[]) {
	base b(10);
	cout << "b.getval() = " << b.getval() << endl;
	base b2 = b;
	cout << "b2.getval() = " << b2.getval() << endl;
	b.setval(200);
	cout << "---after set--" << endl << "b.getval() = " << b.getval() << endl << "b2.getval() = " << b2.getval() << endl;

}
