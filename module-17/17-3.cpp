// Random Set: Write a method to randomly generate a set of m integers from an array of size n. Each element must have equal probability of being chosen.

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int* GenerateArrayElements(int* arr, int size, int m) {
	srand(time(NULL));
	int* subarr = new int[m];
	for(int i = 0; i < m; ++i) // just copy original array, m element
		subarr[i] = arr[i];

	for(int i = m; i < size; ++i) {
		int k  = rand() % (i+1);
		if(k < m)
		subarr[k] = arr[i];
	}
	return subarr;
}

void DisplayArray(int* arr, int size) {
	for(int i =0; i < size; ++i)
		cout << arr[i];
	cout << endl;
}

int main() {
	int size, m; 
	cout << "Enter size of your sub array 1-9 = " ; cin >> m;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	size = sizeof(arr)/sizeof(arr[0]);
	int *subarr = GenerateArrayElements(arr,size, m);
	DisplayArray(subarr, m);
}
