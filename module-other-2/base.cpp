#include<iostream>
using namespace std;

class base {
	virtual void method()  { cout << " from base" << endl; }
public:
	base() { method(); }
	virtual ~base() { method(); }
	void basemethod() { method(); }
};

class derive : public base {
	void method() { cout << " from derive " << endl; }
public:
	derive() { method(); }
	~derive() {method(); }
	void derivemethod() { method() ;}
};

int main(int argc, char* argv[]) {
base* b = new derive;
b->basemethod();
delete b;
cout << endl;

derive* d = new derive;
d->derivemethod();
delete d; 
return 0;
}



/*class Base {
    virtual void method() {std::cout << "from Base" << std::endl;}
public:
    virtual ~Base() {method();}
    void baseMethod() {method();}
};

class A : public Base {
    void method() {std::cout << "from A" << std::endl;}
public:
    ~A() {method();}
};

int main(void) {
    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}*/
