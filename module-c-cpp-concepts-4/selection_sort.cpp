// selection sort
// source http://www.geeksforgeeks.org/selection-sort/

#include<iostream>
using namespace std;

void selectionsort(int* arr, int size) { 
		// you can use selectionsort(int arr[], int size) as well
	for(int i =0; i < size; ++i) {
	//	int small = arr[i]; // it will help to avoid swaping eachtime
		int position = i;
		for(int j = i+1; j < size; ++j) {
			if(arr[position] > arr[j]) {
		//		small = arr[j];
				position = j;
			}
		}
	//	if(position != 0) {  
		int tmp = arr[i];
		arr[i] = arr[position];
		arr[position] = tmp;
	//	}
	}
}


int main() {
	int arr[5] = { 1, 6, 4, 3, 0};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	selectionsort(arr, arr_size);
	for(int i = 0; i < arr_size; ++i)
		cout << arr[i] << endl;
}
