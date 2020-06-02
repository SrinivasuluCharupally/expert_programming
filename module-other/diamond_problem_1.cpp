// diamond problem
// if you write getweight() in B and C then make sure to write in D also
// otherwise ambigous 

// source https://mcodegeeks.com/c-whats-diamond-problem-can-avoided/
#include<iostream>
using namespace std;


class A {
	int weight;
  public:
	virtual int getweight() { weight = 10; return weight; }
};

class B : virtual public A { // virtual should be in both places
};

class C : virtual public A { // virtual should be in booth places

};

class D : public B, public C { // D does not have getweight, inherited from A 
};

int main() {
	D d_obj;
	cout << d_obj.getweight()  << endl;
	A* a = new D;
	cout << a->getweight() << endl;
}