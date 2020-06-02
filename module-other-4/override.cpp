#include <iostream>
#include <string>
using namespace std;

class base {
  public:
	virtual void fun(){
		cout << "base class" << endl;
	}
};
class derived : public base {
  public:
	void fun() override  {
		cout << " derived class" << endl;
	} 
};

int main() {
base obj1;
derived obj2;
obj1.fun();
obj2.fun();

base* b = new derived;

 b->fun();
}

