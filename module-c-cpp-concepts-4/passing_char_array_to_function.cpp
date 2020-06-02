#include<iostream>
using namespace std;

void fun(const char* c) { // you see warning if you dont use const
	c = "hi"; // this will not affect because pointer is const
}

void fun2(char* k1) {
	k1 = "me";
}

void fun3( char* k) {
	k[1] = 'k'; // you cant change any element in  the array since it has to be const for c++11...
}
void fun4(int *a) {
	a[1] =3;
}
int main() {

	const char* c = "helo"; // you see warning if you dont use const
	cout << "before " << c << endl;
	fun(c);
        cout << "after " << c << endl;
	c[2] ='u'; // this is not allowed because c is const

	char* k = "bye";
        cout << "before " << k << endl;

	fun2(k);
        cout << "after " << k << endl;
	fun3(k); // you cant change element even it's not const...
	cout << "chaning one charecter " << k << endl;

	int a[] = {1,2}; // int* a = {1,2}, it does not work.... no memory allocated for {1,2} ..., it shoudl be int a[] = {1,2}... a[] act as pointer
	int* k1 = a; // you cant do int* k1 = &a, it becomes address of pointer, k has to be double pointer in that case. a is nothing but address of first element

	fun4(a);
//	const int* p = {1,2};// this is not allowed because memory not alocated for {1,2}	

	int *p = new int(1,2); // this is also not allowed, *p requires address only
	int * p = new int[5]; // the *p saves address of first element of array which is equal to int* p = {1,2,3,4,5} but you can change value in new int[];
}
