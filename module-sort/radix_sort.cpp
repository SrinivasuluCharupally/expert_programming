// radix sort
// source http://www.geeksforgeeks.org/radix-sort/

#include<iostream>
using namespace std;

void sort(int*, int, int);
int Max(int*, int);

int Max(int* arr, int size) {
	int max_position = 0;
	for(int i =1; i < size; ++i) {
		if(arr[i] > arr[i-1]) 
			max_position = i;
	}
	return arr[max_position];
}

void sort(int* arr, int size, int div) {
	int output[size];
	int i, count[10] = {0};
	for(int i = 0; i < size; ++i)
		count[(arr[i]/div)%10]++;

	for(int i = 1; i < 10; ++i)
		count[i] += count[i-1];
/*
	for(int i = 0; i < size; ++i) {
		if((count[(arr[i]/div)%10]) >= 0) {
		output[count[(arr[i]/div)%10] - 1] = arr[i];
		}
		count[(arr[i]/div)%10]--;
	}
*/

	for(int i = size-1; i >= 0; i--) {
		output[count[(arr[i]/div)%10] - 1] = arr[i];
		count[(arr[i]/div)%10]--;
	}

	for(int i =0; i < size; ++i)
		arr[i] = output[i];
}


void Radixsort(int* arr, int size) {
	int max = Max(arr, size);
	for(int div = 1; max/div > 0; div *= 10)
		sort(arr, size, div);

}

int main() {
	int arr[5] = { 420, 320, 30, 4, 2 };
	int size = sizeof(arr) /sizeof(arr[0]);

	Radixsort(arr, size);
	for(int i = 0; i < size; ++i)
		cout << arr[i] << endl;
}


