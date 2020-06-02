#include<iostream>
using namespace std;

class base {
	int i;
public:
	base() : i(10) {  }
	int getval() { return i;}
};

int main(int argc, char* argv[]) {
base b1, b2;
b1 = b2;
base b3;
b3 = b2;
cout << "b1 = " << b1.getval() << endl << "b2 = " << b2.getval() << endl << "b3 = " << b3.getval() << endl;
}
