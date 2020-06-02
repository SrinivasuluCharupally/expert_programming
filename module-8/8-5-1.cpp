
// Recursive Multiply: Write a recursive function to multiply two positive integers without using the * operator (or / operator). You can use addition, subtraction, and bit shifting, but you should minimize the number of those operations

// optimized code
//book, solution#3

#include<iostream>
using namespace std;

int MulWithoutSymbolOptimized(int , int);

int MulWithoutSymbolOptimized(int small, int big) {
	if(small == 0) return 0;
	int res = big + MulWithoutSymbolOptimized(small-1, big);
	return res;
}

int main() {
	int a = 10, b = 7;
	int small = a>b?b:a;
	int big = a>b?a:b;
	int res;
	if(small%2 == 1) {
		res = MulWithoutSymbolOptimized(small/2 , big);
		res = res << 1;
		res = res + big;
	}
	else {
		res = MulWithoutSymbolOptimized(small/2 , big);
		res = res << 1;
	}

	cout << "Mul of two numbers without *, optimized = " << res << endl;
}
