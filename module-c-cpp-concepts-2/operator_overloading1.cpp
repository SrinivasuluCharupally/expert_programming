#include<iostream>
using namespace std;

class opt {
	int i;
public:
	opt() : i(0) {}
	int operator+(const opt& obj2) {
		cout << " Fist value = " << this->getvalue() << endl;
		cout << " Second value = "  << obj2.getvalue() << endl;
		return i = this->getvalue() + obj2.getvalue();
	}
	int getvalue() const {
		return i;
	}
	void setvalue(int v) {
		i = v;
	}
};

int main(int argc, char* argv[]) {
	opt p1, p2;
	p1.setvalue(10);
	p2.setvalue(20);
	int total = p1 + p2;
cout << " Sum of i value = "  << total << endl;
}

