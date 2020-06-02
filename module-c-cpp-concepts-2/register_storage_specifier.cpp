#include<iostream>
using namespace std;

int main() {
int i = 10;
register int r = 20;

cout << "size of i = " << sizeof(i) << "  Address = " << &i << endl;
cout << "size of reg = " << sizeof(r) << "  Address = " << &r << endl;

}

