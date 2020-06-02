#include<iostream>
using namespace std;

class base {
	int count;
public:
	base() :count(0) {}
	void operator ++() {
	count = count + 1;
	}

	void display() {
	cout << "Value = " << count << endl;
	}
};

int main() {
	base b;
	++b; ++b;
int k=0; ++k;
	b.display();
}
