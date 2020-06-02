#include<iostream>
using namespace std;

class base{
public:
	base() { }
};

class derive:public base {
public:
	derive() {}
};

int main() {
base b;
derive d;
b = d;
//d = b;
}
