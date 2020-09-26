// finding no of zeros in factorial of given number

// source book
#include<iostream>
using namespace std;

int countingzeros(int n) {
	int count = 0;
	for( int i = 5; n/i > 0; i += 5) 
		if(n%i ==0) count += 1;
			

	return count;
}
int factorial(int n) {
	if(n <= 0) return 1;
	return n*factorial(n-1);
}
int main() {
	int n = 5;
	cout << "factorial of 5! = " << factorial(n) << endl;
	cout << "no of zeros of 5! = " << countingzeros(n) << endl;

}
