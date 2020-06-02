// Permutations without Dups: Write a method to compute all permutations of a string of unique characters.


//source http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<iostream>
#include<string>
#include<stdio.h>
#include<set>

using namespace std;

void swap(char* x, char* y) {
	char tmp = *x;
	*x = *y;
	*y = tmp;
}

void AllPermutationsOfString(char* c, int left, int right) {
	int i;
	if(left == right) printf("%s\n", c);
	else {
		for( i =left; i <= right; i++) {
			swap((c+left), (c+i));
			AllPermutationsOfString(c, left+1, right);
			swap((c+left), (c+i));
		}
	}
}


int main() {
	char s[] = "ABC";
	int length = sizeof(s)/sizeof(s[0]);
	cout << length << endl;
	AllPermutationsOfString(s,0,length-1); 
	return 0;
}


