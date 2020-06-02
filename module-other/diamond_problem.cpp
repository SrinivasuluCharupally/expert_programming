// diamond problem

// source https://mcodegeeks.com/c-whats-diamond-problem-can-avoided/
#include<iostream>
using namespace std;


class A {
	int weight;
  public:
	virtual int getweight() { weight = 10; return weight; }
};

class B : virtual public A { // virtual should be in both places
public: int weight;
        int getweight() { weight = 20; return weight; }

};

class C : virtual public A { // virtual should be in booth places
public: int weight;
        int getweight() { weight = 30; return weight; } // this gives ambigous

};

class D : public B, public C { // D does not have getweight, inherited from A 
public: int weight;
       int getweight() { weight = 40; return weight; } // this gives ambigous

};

int main() {
	A* a = new D;
	cout << " ouput = " << a->getweight() << endl;
}



