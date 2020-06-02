// Number Max: Write a method that finds the maximum of two numbers. You should not use if else or any other comparison operator.

// source book

#include<iostream>
using namespace std;

int main() {
	int a , b  ;
	cout << "Enter a and b values " << endl << "a =" ;
	cin >> a;
	cout << endl << "b = ";
	cin >> b;
	
//	int max = sign(a-b)?b:a;
	int max = ((a-b) >> 31) ? ((b-a)>>31 ? a :b) :a;
	cout << "Max = " << max << endl;
}
	
