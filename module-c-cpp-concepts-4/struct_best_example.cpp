// accessing struct elements properly
// accessing struct elements without knowing the variable name

#include <iostream>
using namespace std;

typedef struct kk { int i; int* p; } kk_t;
kk_t *arg;

int main() {
arg = new kk_t;
int *ptr = new int;
*ptr = 3;
arg->i = 2;
arg->p = ptr;
cout << "sizeof = " << sizeof(kk_t) << endl;
cout << arg << endl;
cout << arg->i << endl;
//cout << *arg->i << endl; //  error: invalid type argument of unary ‘*’ (have ‘int’)
cout << arg->p << endl;
cout << *arg->p << endl;
cout << arg+8 << endl;
int* k = (int*)(arg); // this is how you can get the value at address without knowing variable name
cout << k << endl;
*k = 20;
cout << *k << endl;
cout << *(k+8) << endl;
}

/*
output:
========
sizeof = 16
0xbd3c20
2
0xbd3c40
3
0xbd3ca0
0xbd3c20
20
3
*/
