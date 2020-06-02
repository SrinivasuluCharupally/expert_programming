// diamond problem 
// // if you write getweight in B and C then it should be in D also
// other wise it's ambigous
// else write only in B or C so that ambigous will not occur

// source https://mcodegeeks.com/c-whats-diamond-problem-can-avoided/
#include<iostream>
using namespace std;


class A {
	int weight;
  public:
	 int getweight() { weight = 10; return weight; }
};

class B : virtual public A { // virtual should be in both places
//public: int weight;
  //      int getweight() { weight = 20; return weight; }

};

class C : virtual public A { // virtual should be in booth places
public: int weight;
        int getweight() { weight = 20; return weight; } // this gives ambigous

};

class D : public B, public C { // D does not have getweight, inherited from A 
};

int main() {
	D d_obj; 
	cout << " ouput = " << d_obj.getweight() << endl;
}



