// access specifiers, private, protected, public.

#include <iostream>
using namespace std;

class base {
    int pri;
    protected: int pro;
    public:
    int pub;
    static int statint;
    base():pri(10), pro(20), pub(30) { cout << " i am base " << endl; }
    void func(void) { int i = 20; }
};
int base::statint = 40;

class derived : public base {
    public:
    derived() {
        cout << " i am derived " << endl;
         //  cout << base::pri << endl; // compiler error because pri is private
          cout << "derived " << base::pro << endl; // inheritance helps, no need of static 
          cout << "derived " << base::pub << endl; // inheritance helps, no need of static 
    }
};

class derived1 {
    base b; // this is nothing but having a object in main() function, not inherited
};

int main() {
	// your code goes here
  base b;
  derived d;
  // cout << b.pri << endl; // compiler error because pri is private
  // cout << b.pro << endl; // compiler error because pro is protected
  cout << b.pub << endl;
  // cout << base::pub << endl;  // non static of base. it works if it's static or inside inherited class
  cout << base::statint << endl; // only static members can be access like base::i 
  cout << d.pub << endl; // it works because base is inherited to derived
 // cout << d.pro << endl; // compiler error because pro is protected variable of base so only with in inherited class can access
}
