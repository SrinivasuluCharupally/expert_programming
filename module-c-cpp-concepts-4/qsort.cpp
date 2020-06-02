// qsort cant not be used for string , qsort is c function ...

// https://stackoverflow.com/questions/40439356/how-to-use-qsort-to-sort-array-of-string-in-c

#include<iostream>
#include<stdlib.h>
using namespace std;

// input  parameters for comparie has to be const void, else error
int comparie (const void* a , const void* b) {
	return ( (*(int*)a) - (*(int*)b));
}
int main() {
	int a[4] = {4,1,9,5};
	qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), comparie);
	for(int i = 0; i < 4; ++i) cout << a[i] << " " << endl;
	
}

