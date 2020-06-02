#include <iostream>
using namespace std;

int main() {
int a=0, b=1, c=2, d=3;
a = (b++, c++, d++);
//  This example increments a list of variables and uses the
//  last one as the rvalue:
cout << "a value = " << a << endl;
a = b++, c++, d++;
cout << "a value without paranthesis = " << a << endl;
}
