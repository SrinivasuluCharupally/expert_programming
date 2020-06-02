//double pointer

#include<iostream>
using namespace std;

int main() {
	int** doublePointer;
	int* singlePointer;
	doublePointer = new int*[3];
	singlePointer = new int[2];
	int k = 10;
	cout << " address of &k " << &k << endl;
	int* regularpointer = &k;
	
	cout << "value at regularpointer " << regularpointer << endl;
	cout << "address of regularpointer " << &regularpointer << endl;

	int* arraypointer;
	int a[2] = {1,2};
	arraypointer = a;
	
	cout << "value at a[0] " << a[0] << endl;
	cout << " address &a[0] " << &a[0] << endl;
	cout << "value at arraypointer " << arraypointer << endl;
	cout << "address of &arraypointer " << &arraypointer << endl;

	

	*(singlePointer+1) = 10;
	*(singlePointer+2) = 20;
	singlePointer[1] = 30; // different way of assigning value
	cout << " value of singlePointer " << singlePointer << endl;
        cout << " value of singlePointer[1] " << singlePointer[1] << endl;




	doublePointer[0] = &singlePointer; // doublePointer[0] can hold only address of vairable but &singlepointer is nothing but two lined address
        doublePointer[1] = a;
        doublePointer[2] = singlePointer;
	cout << "value of  doublePointer[0] " <<  doublePointer[0] << endl;
        cout << "address of  &doublePointer[0] " <<  &doublePointer[0] << endl;
        cout << "value of  doublePointer[1] " <<  doublePointer[1] << endl;
	cout << "pulling a[1] using doublePointer[1] " << *(doublePointer[1]+1) << endl;

        cout << "pulling a[1] using doublePointer[1] other way " << (doublePointer[1])[1] << endl;

	cout << " value of doublePointer " << doublePointer << endl;
        cout << "  &doublePointer " <<  &doublePointer << endl;

	int* dynamicPointer = new int[1];
	cout << "value at dynamicPointer " << dynamicPointer << endl;

	int** d;
	int* s = &k;
	d = &s;
	cout << "value at double pointer " << d <<endl;
	cout << "accesing value using double pointer " << d[0] << endl;
	cout << "address of single pointer " << s << endl;

	d = s;


