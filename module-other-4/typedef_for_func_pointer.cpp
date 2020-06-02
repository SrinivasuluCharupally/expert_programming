// source https://stackoverflow.com/questions/11038430/how-to-create-a-typedef-for-function-pointers

#include<iostream>
using namespace std;

int foo(int i){ return i + 1;}

typedef int (*g)(int);  // Declare typedef

int main() {
	g func = &foo;          // Define function-pointer variable, and initialise

	int hvar = func(3);     // Call function through pointer
	cout << hvar << endl;
}
