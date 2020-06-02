#include<iostream>
using namespace std;

class base {
 	//static int i;
public:
	static int i;
	const int c;
	base() : c(0) {cout << "helo base" << endl; }
	void assign(int val) { 	//i = val; }
		cout << ++i << endl;	}
	//~base() {cout << i << endl; }
};

int base::i = 1;

int main() {
//int base::i = 0;
base b1, b2;
b1.assign(10);
b2.assign(20);
}
