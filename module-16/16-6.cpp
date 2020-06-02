// Smallest Difference: Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.


// source book

#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int a[5] = {4, 1, 10, 6,7};
	int b[5] = {8, 70, 20, 3, 25};

	qsort(&a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), compare);
	qsort(&b, sizeof(b)/sizeof(b[0]), sizeof(b[0]), compare);

	for(int i = 0; i < 5; ++i)
		cout << a[i] << " " << b[i] << endl;
	int diff, ai, bi, mindiff;
	for(int i = 0; i < 5; ) 
		for(int j = 0; j < 5; ) {
			diff = abs(b[j] - a[i]);
			if(i == 0) {++i; mindiff = diff; }
			else { if(diff < mindiff) { mindiff = diff; ++i;}
				else { ++i; ++j; }
			}	
		}
	cout << "min diff = " << mindiff << endl;
}

