#include<iostream>
using namespace std;

class base {
 	int i;
public:
	base() {cout << "constructor" << endl;  i=0; }
	~base() {cout << "destructor" << endl; }
};

void static_fun() {
base b;
}

int main() {
static_fun();
cout << " end of program" << endl;
}


