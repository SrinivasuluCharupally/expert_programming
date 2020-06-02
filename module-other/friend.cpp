#include<iostream>
using namespace std;

struct X;

struct Y {
	void f(X*);
};

struct X {
  private: int i;
  public: 
  friend void Y::f(X*);
};

void Y::f(X* x) {
	x->i = 10;
	cout << x->i << endl;
}

int main() {
	struct X a;
	struct Y b;
	b.f(&a);
}
