// binary search 
// source http://www.geeksforgeeks.org/binary-search/


#include<iostream>
using namespace std;


int BinarySearch(int* arr, int low, int high, int find_element) {
	int mid = (high+low)/2;
	if(arr[mid] == find_element) return mid;

	if(arr[mid] > find_element) {
		return BinarySearch(arr, low, mid, find_element); // return helps to comme out of iteration immediatly, no need to trace back, backtrace, it's optimized. No issue even if you dont use it..., it's worst case
	}
	else {
                return BinarySearch(arr, mid+1, high, find_element);
	}

	return -1; // not found
}

int main(int argc, char* argv[]) {
	int arr[5] = {  1, 12, 13, 20, 25,};

	int size = sizeof(arr)/sizeof(arr[0]);

	int find_element = 20;
	int element_index = BinarySearch(arr, 0, size, find_element);
	cout << find_element << " index  = " << element_index << endl;
}
