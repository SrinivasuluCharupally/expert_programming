// Missing Int: Given an input file with  4 billion non-negative integers, provide an algorithm to generate an integer that is not contained in the file. Assume you have 1 GB of memory available for this task.

//missing number in 4 billon numbers...
// use bool array for 4billion numbres so it requires only 512MB space
// print the first false from bool array

// 10MB, if you want to use only 10MB then divide the file to chunks then do same things
// source https://www.careercup.com/question?id=14804692

// use bitset instead bool, http://www.cplusplus.com/reference/bitset/bitset/bitset/

#include<iostream>
using namespace std;


int main() {
	bool b[10];
	fill_n(b, 10, false);
	int arr[9] = { 1,2,3,4,5,6,7,8,10};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i < size; ++i) 
		b[arr[i]] = true; 
	int i = arr[0]; // this is impartant, else b[0] is false
	while(b[i])
		++i;

	cout <<  "Missing number in given arr = " << i << endl;
}
