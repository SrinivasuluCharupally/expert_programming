// bubble sort, optimized algo, using "swaped" chcked
// source http://www.geeksforgeeks.org/bubble-sort/



#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

int main() {

	int arr[5] = {1, 5, 4, 9, 0 };
	bool swaped = false;
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
		for(int j = 1; j < sizeof(arr)/sizeof(arr[0]); ++j){
			if(arr[j-1] > arr[j]) {
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
				swaped = true; // you can break directly, swapped not require 
		}
		if(!swaped) break;
	}
	for(int i =0; i<sizeof(arr)/sizeof(arr[0]); ++i) 
		cout << arr[i] << " " << endl;

}
