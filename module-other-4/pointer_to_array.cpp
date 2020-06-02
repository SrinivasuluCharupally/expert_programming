#include<iostream>
using namespace std;

int main() {
	int* p = new int[2]; // two integer blockes are allocated and starting address stored in p
	*p = 12;
	*(p+1) = 13;
	cout << "p[0] address = " << p << " value =  " << *p << endl;
	cout << "p[1] address = " << p+1 << " value = " << *(p+1)<< endl;
	cout << "&P address" << &p << endl;
}
