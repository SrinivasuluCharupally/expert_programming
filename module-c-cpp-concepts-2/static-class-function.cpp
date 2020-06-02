#include<iostream>
using namespace std;

class base {
public:
	 void fun();
};

void base::fun() { int i = 0; i++; cout << "static class fun " << i << endl; }

int main() {
base b1, b2;
b1.fun();
b2.fun();
base::fun();
base().fun();
}

