#include<iostream>
using namespace std;

class opt {
	int i;
public:
	opt() : i(0) {}
	void operator++ () {
		i = this->getvalue() + 1;
	}
	opt operator ++(int) {
		opt obj;
		i = this->getvalue() + 1;
		return obj;
	}
	void setvalue(int k) {
		i = k;
	}
	int getvalue() const {
		return i;
	}
};

int main() {
opt obj;
obj.setvalue(20);
obj++;
cout << "post increment" << obj.getvalue() << endl;
++obj;
cout << "pre increment" << obj.getvalue() << endl; 

}
