#include <iostream>
using namespace std;

class test {
private: int total;
public: test(int item) {
	total = item;
	}
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
}
