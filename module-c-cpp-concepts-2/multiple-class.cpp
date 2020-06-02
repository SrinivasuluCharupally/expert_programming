#include<iostream>
using namespace std;

class base {
public:
int i;
void fun() { cout << "helo" << endl; }
  class base2{
	public:
	int j;
        void fun2() { cout << " fun2 " << endl; }
	};
};

int main() {
//base().base2().j=0;
base::base2 b2;
cout << base().i << endl;
b2.j=10;
base().fun();
base::base2().fun2();
b2.fun2();
}

