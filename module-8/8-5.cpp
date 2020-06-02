
// Recursive Multiply: Write a recursive function to multiply two positive integers without using the * operator (or / operator). You can use addition, subtraction, and bit shifting, but you should minimize the number of those operations

#include<iostream>
using namespace std;

int MulWithoutSymbol(int,int);


int MulWithOutSymbol(int small, int big) {
	if(small == 0) return 0;
	int res =big + MulWithOutSymbol(small-1, big);
	return res;
}

int main() {
	int a = 10,  b = 5;
	int small = a>b ? b:a;
	int big = a>b ? a:b;
	int res = MulWithOutSymbol(small, big);
	cout << " result of multiplying without using * = " << res << endl;
}
