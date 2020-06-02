// shufle: Write a method to shuffle a deck of cards. It must be a perfect shuffle-in other words, each of the 52! permutations of the deck has to be equally likely. Assume that you are given a random number generator which is perfect.


// source http://www.geeksforgeeks.org/shuffle-a-given-array/

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void ShuffleArray(int* arr, int size) {
	srand(time(NULL));
	for(int i = 1; i < size; ++i) {
		int pos = rand() % (i+1) ;
		Swap(&arr[i], &arr[pos]);
	}
}

void DisplayArray(int* arr, int size) {
	for(int i =0; i < size; ++i)
		cout << arr[i];
	cout << endl;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int size = sizeof(arr)/sizeof(arr[0]);
        DisplayArray(arr, size);
	ShuffleArray(arr, size);
	cout << "After shuffle ..." << endl;
	DisplayArray(arr, size);
}
