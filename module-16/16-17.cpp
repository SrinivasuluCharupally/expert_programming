// Contiguous Sequence: You are given an array of integers (both positive and negative). Find the contiguous sequence with the largest sum. Return the sum

// source book


#include<iostream>
using namespace std;

typedef struct sequence{
	int min;
	int max;
} sequence_t;
int sum = 0;
sequence_t seq;
void FindSequenceSum(int* arr, int size) {
	sum = arr[0];
	for(int i = 1; i < size;) {
		
		if(sum > (arr[i] + sum)) {
			if(++i >= size) break;
			sum = arr[i];
			seq.min = i; // it's not fully accurate, it missing index 0
		}
		else {
			 sum += arr[i];
			 seq.max = i;
		}
		//sum += arr[i+1];
		i++;
	}
}		
void Sequence(int* arr) {
	for(int i = seq.min; i <= seq.max; ++i)
		cout << " " << arr[i];
	cout << endl;
}
int main() {
	int arr[] = {2, -8, 3, -2, 4, -10};
	int size = sizeof(arr)/sizeof(arr[0]);
	FindSequenceSum(arr, size);
	cout << "Sum = " << sum  << endl;
	Sequence(arr);
}
