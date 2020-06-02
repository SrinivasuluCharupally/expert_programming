#include<iostream>
using namespace std;

class base {
int i;
public:
int getvalue() { i = 10; return i; }
};

class deriveL :  virtual public base {
};

class deriveR : virtual public base {
};

class problem : public deriveL, public deriveR {
};

int main() {
problem p;
int k = p.getvalue();
cout << " value " << k << endl;
}


