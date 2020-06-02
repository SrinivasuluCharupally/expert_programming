// all combinations of string, having dublicate characters in string, recusive technique
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

void AllPermutationsOfString(set<string>* setOfCombinations, char* c, int left, int right) {
	
	if(left == right) { printf("%s\n", c); setOfCombinations->insert(c); }
	else {
		for( Int i =left; i <= right; i++) {
			swap((c+left), (c+i));
			AllPermutationsOfString(setOfCombinations, c, left+1, right);
			swap((c+left), (c+i));
		}
	}
}


int main() {
	char s[] = "AABC";
	int length = sizeof(s)/sizeof(s[0]);
	cout << length << endl;
	set<string>* setOfCombinations = new set<string>;
	AllPermutationsOfString(setOfCombinations, s,0,length-2);

	cout << "Avoid dublicate permutations" << endl ;
	for(set<string>::iterator itr = setOfCombinations->begin(); itr != setOfCombinations->end(); ++itr)
		cout << *itr << endl;

	return 0;
}


