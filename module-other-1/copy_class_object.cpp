#include<iostream>
using namespace std;

class X {
public: int i;
};



int main() {
X x,y,z;
x.i = 10;
y.i = 20;
cout << "x " << x.i << "y " <<  y.i << endl;
z = x;
cout << "z " << z.i << endl;
}



