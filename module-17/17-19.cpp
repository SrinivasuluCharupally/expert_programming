// Missing Two: You are given an array with all the numbers from 1 to N appearing exactly once, except for one number that is missing. How can you  nd the missing number in O(N) time and 0(1) space?What if there were two numbers missing?

// soruce book

// runtime O(n) & space O(1)

#include<iostream>
using namespace std;

int FindMissing(int* arr, int size) {
	int expectedProduct=1, expectedSum=0;
	int actualProduct = 1, actualSum = 0;
	for(int i = 0; i < size; i++) {
//		expectedProduct = expectedProduct*arr[i];
		expectedSum = expectedSum + arr[i];
	
//		actualProduct = actualProduct*(i+1);
//		actualSum = actualSum + (i+1);
	}
	int n = size+1;
	actualSum = n*(n+1)/2 ;
	return (actualSum - expectedSum);
}
	

int main() {
	int arr[] = {1,2,3,4,5,6,7,9};
	int size = sizeof(arr)/sizeof(arr[0]);

	int missing = FindMissing(arr,size);
	cout << "Missing number = " << missing << endl;
}
