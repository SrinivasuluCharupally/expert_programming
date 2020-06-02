// powerset , power set, not optimized
// source http://www.geeksforgeeks.org/power-set/


#include<iostream>
#include<math.h>
using namespace std;

void PowerSet(char* set, int size) {
	int noOfCombinations = pow(2,size);
	for(int i = 0; i < noOfCombinations; ++i) {
		for(int j = 0; j < size; ++j) {
			if(i & (1<<j)) {
				cout << set[j];
			}
		}
		cout << endl;
	}
}


int main() {
	char set[3] = {'a', 'b', 'c'};
	PowerSet(set, 3);
}
	
