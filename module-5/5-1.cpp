//Insertion: You are given two 32-bit numbers, N and M, and two bit positions, iand j. Write a method to insert Minto N such that M starts at bit j and ends at bit i. You can assume that the bits j through ihave enough space to fit all of M. That is, if M= 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3and i= 2, because Mcould not fully  t between bit 3 and bit 2.


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n = 1024, m = 19, i = 2, j = 6;
	int left = (-1<<j); // equal to ~0, all 1s
	int right = (1<<(i+1)) -1;
	int clear = left | right;
	n = n & clear;
	m = m << i;
	n = n | m;
	cout << "output = " << n << endl;
	
	return 0;
}

