// size of base is 4*2variables = 8
// size of derive is base size + 4*1variable = 12
// if i marke base getval() as virtual then base of base and derive increase by 8bytes,  i.e base = 18, derive = 24
// d.getval() will not call base::getval() directly because object has to be pointer type then only polymorphisam occurs
// if you mark the base variables as protected then you can access them directly from derived class like, base::b
// you cannot access protected from derived class object

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class base {
	int a;
protected:
	int  b;
 public:
	base(int v) : a(v) , b(v+1){}
        virtual void getval() { cout << " base val = " << a << endl; }
};

class derive :public base {
	int x;
	//base b1(2);
 public:
	derive(int v) : base(v) {}
	void getval() { int k = 10; cout << " derive val = " <<  base::b << endl;
	base::getval(); }
};

int main() {

derive d(10);
d.getval();
cout << "sizeof derive = " << sizeof(d) << endl;
base b(20);
cout << "sizeof base = " << sizeof(b) << endl;
//cout << "accessing base member b =" << d.b << endl; // this gives error because b is protected
printf("base adderess  = %p \n ", &b);
printf("derive address = %p \n", &d);
}


