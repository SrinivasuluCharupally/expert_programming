// Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown number of times, write code to  nd an element in the array. You may assume that the array was originally sorted in increasing order

// source http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/ 


#include<iostream>
using namespace std;


int BinarySearch(int* arr, int low, int high, int find_element) {
	int mid = (high+low)/2;
	if(arr[mid] == find_element) return mid;

	if(arr[mid] > find_element && arr[low] <= find_element) {
		return BinarySearch(arr, low, mid, find_element);
	}
	else {
		if(arr[mid] > find_element && arr[high-1] >= find_element) {
                	return BinarySearch(arr, mid+1, high, find_element);
		}
	}
	return -1;
}

int main(int argc, char* argv[]) {
//	int arr[5] = {20, 25, 1, 12, 13};
	int arr[7] = {2,3,4,5,6,7,1};

	int size = sizeof(arr)/sizeof(arr[0]);

	int find_element = 1;
	int element_index = BinarySearch(arr, 0, size, find_element);
	cout << find_element << " index  = " << element_index << endl;
	return 0;
}
