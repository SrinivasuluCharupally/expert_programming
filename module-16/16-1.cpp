// swaping two numbers...
// source book


#include<iostream>
using namespace std;

void usingmul(int* a, int* b) {
	*a = (*a) * (*b);
	*b = (*a)/(*b);
	*a = (*a)/(*b);
}

void usingadd(int* a , int* b) {
	*a = (*a) + (*b);
	*b = *a - *b;
	*a = *a - *b;
}

void usingbit(int* a , int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}


int main() {
	int a = 5, b = 4;
        cout << " given = " << a << " " << b << endl;
	usingmul(&a,&b);
	cout << " swaped using mul = " << a << " " << b << endl;
	usingadd(&a,&b);
        cout << " swaped using add = " << a << " " << b << endl;
	usingbit(&a,&b);
        cout << " swaped using bit = " << a << " " << b << endl;
}


