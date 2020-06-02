// size of base is 4*2variables = 8
// size of derive is base size + 4*1variable = 12
// if i marke base getval() as virtual then base of base and derive increase by 8bytes,  i.e base = 18, derive = 24
// d.getval() will not call base::getval() directly because object has to be pointer type then only polymorphisam occurs

#include<iostream>

using namespace std;

class base {
	int a, b;
 public:
	base(int v) : a(v) , b(0){}
        virtual void getval() { cout << " base val = " << a << endl; }
};

class derive :public base {
	int x;
	//base b1(2);
 public:
	derive(int v) : base(v) {}
	void getval() { cout << " derive val = " << endl;
	base::getval(); }
};

int main() {

derive d(10);
d.getval();
cout << "sizeof derive = " << sizeof(d) << endl;
base b(20);
cout << "sizeof base = " << sizeof(b) << endl;

}


