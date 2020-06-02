#include<iostream>
using namespace std;

class base {
	static int i;
public:
	base() { cout << " hi " << i << endl; i++; }
};

int base::i=0;

int main() {
base b, b1, b2;
}
