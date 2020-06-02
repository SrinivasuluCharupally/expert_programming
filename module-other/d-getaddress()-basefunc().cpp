
#include <iostream>
using namespace std;

class base {
  public:
  void baseFunc() { cout << "i am base" << endl; }
  virtual base* getaddress() = 0; // this should be available, else inheritence failed
};

class derived : public base{
    public:
    derived* getaddress() {
        return this;
    }
};

int main() {
    base* d = new derived;
    d->getaddress();
    d->getaddress()->baseFunc();
    d->baseFunc();
}


