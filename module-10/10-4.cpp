// binary search in an infinit size array

//  sorted Search, No Size: You are given an array-like data structure Listy which lacks a size method. It does, however, have an elementAt(i) method that returns the element at index i in 0( 1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data structure only supports positive integers.) Given a Listy which contains sorted, positive integers,  nd the index at which an element x occurs. If x occurs multiple times, you may return any index.


// source http://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/


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

int Search(int* arr, int find_element) {
	int high=1, low=0;
	while(arr[high] <  find_element) {
		low = high;
		high *= 2;
	}

	return BinarySearch(arr, low, high, find_element);
}

int main(int argc, char* argv[]) {
//	int arr[5] = {  1, 12, 13, 20, 25,};
	 int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};

//	int size = sizeof(arr)/sizeof(arr[0]);

	int find_element = 10;
	int element_index = Search(arr, find_element);
	cout << find_element << " index  = " << element_index << endl;
}
