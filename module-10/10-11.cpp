//  Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal to the adjacent integers and a "valley" is an element which is less than or equal to the adjacent integers. For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. 
//Given an array of integers, sort the array into an alternating sequence of peaks and valleys.EXAMPLEInput: {5, 3, 1, 2, 3} Output: {5, 1, 3, 2, 3}


#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {

	int arr[6] ={3,0,2,7,5,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "GIven array ... " << endl;
        for(int i =0; i < size; ++i)
                cout << arr[i] << endl;

	qsort(arr, size, sizeof(arr[0]),compare);
	cout << "sorted array .. " <<endl;
	for(int i =0; i < size; ++i)
		cout << arr[i] << endl;
	cout << "Peak and vally array .. " << endl;
	for(int i =1; i < size ; i += 2) {
		int tmp = arr[i-1];
		arr[i-1] = arr[i];
		arr[i] = tmp;
	}

        for(int i =0; i < size; ++i)
                cout << arr[i] << endl;


}
