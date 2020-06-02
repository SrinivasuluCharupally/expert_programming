#include <iostream>
using namespace std;

class test {
private: int total;
	 float f , f2, f3 , f4;
	 test* next = NULL;
public: test(int item) {
	total = item;
	}
	test() {}
test& additem(int itemprice) {
	total += itemprice;
	return *this;
	}
void checkout() {
	cout << "total =" << total << endl;
}
};

int main() {
test kk(0);
kk.additem(100).additem(200);
kk.checkout();
cout << " size of class = " << sizeof(kk) << endl;
test* k2 = new test[10];
int* i = new int[10];
cout << "Size of class pointer = " << sizeof(k2) << endl;
cout << "Size of int pointer = " << sizeof(i) << endl;
//k2[0](10);
*i = 10; i++; *i = 20;
}
