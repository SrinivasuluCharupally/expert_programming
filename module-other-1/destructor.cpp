#include<iostream>
using namespace std;

class base {
int i;
public:   base(); // you cant use virtual for constructor so every time base() & derived() const called
	virtual ~base(); // if you dont use virtual then only base() destructor caled
	virtual void fun() { cout << "base fun" << endl; } // if you dont use virtual then base::fun() will be called
	
};

base::base() { cout << "base constructor" << endl; }
base::~base() { cout << "base destructor" << endl; }

class derived : public base {
  public:
	derived() { cout << "derived const" << endl; }
	~derived() { cout << "derived dest" << endl; }
	void fun() { cout << "derived fun" << endl; }
};
	 

int main() {
//base a[3];
base* b = new derived();
b->fun();
delete b;
}
