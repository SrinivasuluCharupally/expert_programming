// you cannot change the content of char* 
// source https://stackoverflow.com/questions/32104799/assignment-of-read-only-location-error-when-assigning-value-of-pointer-to-other

#include<iostream>
using namespace std;

int main() {
 	//const char* p ="hi"; // does not allow to change, make it char[]
	char p[] = "hi";
	p[1] = 'c';
	cout << p << endl;
}
