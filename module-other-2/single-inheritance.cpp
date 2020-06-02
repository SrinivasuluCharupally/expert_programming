#include<iostream>
using namespace std;

class base {
	public:
	base() { cout << " i am base" << endl; }
};

class derive : public base {
	public:
	derive() { cout << "i am derive " << endl; }
};

int main() {
//base b;
derive d;

}
