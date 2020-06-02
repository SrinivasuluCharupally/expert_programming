// MajorityElement:Amajorityelementisanelementthatmakesupmorethanhalfoftheitemsin an array. Given a positive integers array,  nd the majority element. If there is no majority element, return -1. Do this in O(N) time and 0(1) space.

// source 

#include<iostream>
#include<algorithm>
using namespace std;


int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int arr[] = {3, 1, 7, 1, 3, 7, 3, 7, 1, 7, 7};
	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare);

	int count, candidate, prev=0, current;
	for(int i = 1; i < sizeof(arr)/sizeof(arr[0]); ++i) {
		if(arr[i-1] == arr[i]){
			count++;
			candidate = arr[i];
		}
		else { 
			if(prev < count) {
			prev = count; 
			count = 0;
                        candidate = arr[i-1]; }
		}
	}

	cout << "most happening candidate is = " << candidate << endl;

}
