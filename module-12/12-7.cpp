// Virtual Base Class: Why does a destructor in base class need to be declared virtual?

// remove virtual from allocate() and destructor then you see why need virtual for destructor.
// if virtual not defined for destructor then then derived destructor never called then it's memory leak;

// source book

#include<iostream>
using namespace std;

class base {
	int* bp;
  public: 
	virtual void allocate() { 
		bp = new int; 
		cout << "memory allocated for bp" << endl;
	}

	virtual ~base() {
		delete bp;
		cout << "memory freed for bp" << endl;
	}
};

class derived : public base {
	int* dp;
  public:
	void allocate() {
		dp = new int;
		cout << "memory allocated for dp" << endl;
	}

	~derived() {
		delete dp;
		cout << "memory freed for dp" << endl;
	}
};

int main() {
	base* b = new derived;
	b->allocate();
	delete b;
}


		
