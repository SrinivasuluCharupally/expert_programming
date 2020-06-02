// Volume of Histogram: Imagine a histogram (bar graph). Design an algorithm to compute the volume of water it could hold if someone poured water across the top. You can assume that each histogram bar has width 1

// source book & http://www.geeksforgeeks.org/trapping-rain-water/

// runtime O(0) & space O(n)
 

#include<iostream>
using namespace std;

#define MAX_ELEMENT(a,b) a>b?a:b
#define MIN_ELEMENT(a,b) a>b?b:a

int FindWaterLevel(int* arr, int size) {
	int left[size], right[size];
	left[0] = arr[0];
	for(int i = 1; i < size; ++i) {
		left[i] = MAX_ELEMENT(left[i-1],arr[i]);
	//	cout << left[i] << endl;
	}

	right[size-1] = arr[size-1];
	for(int i = size-2; i >= 0; --i) {
		right[i] = MAX_ELEMENT(right[i+1], arr[i]);
//		cout << right[i] << endl;
	}
	int water=0;

	for(int i = 0; i < size; ++i) {
		water += ((MIN_ELEMENT(left[i], right[i])) - arr[i]);
		cout << left[i] << " " << right[i] << " " << arr[i] << " " << water << endl;
	}


	return water;		
}
	
int main() {
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	int water = FindWaterLevel(arr, size);
	cout << "Total water level = " << water << endl;
}






