#include<iostream>
using namespace std;

void fun(int a[]) {
	a[2] = 0;
}

int main() {
	int a[] = {1,2,3};
	fun(a);
	cout << a[2] << endl;
	int* a1 = {1,2,3}; // this is not allowed, 
			   //should be int* a1 = new int[3];
	fun(a1);
	cout << a1[2] << endl;
}
