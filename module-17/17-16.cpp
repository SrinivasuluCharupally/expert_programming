// The Masseuse: A popular masseuse receives a sequence of back to-back appointment requests and is debating which ones to accept. She needs a 15-minute break between appointments and therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appoint­ ment requests (all multiples of 15 minutes, none overlap, and none can be moved),  nd the optimal (highest total booked minutes) set the masseuse can honor. Return the number of minutes.

// source book

// runtime O(n) & space O(1) , optimal solution #4

// recursion takes O(2^n) so this is not recomanded

#include<iostream>
using namespace std;

int MaxMinutes(int* arr, int size) {
	int oneAway = 0;
	int twoAway = 0;
	for(int i = size-1; i >=0; --i) {
		int bestwith = twoAway + arr[i];
		int worst = oneAway;
		int current = bestwith > worst ? bestwith : worst;
		twoAway = oneAway;
		oneAway = current;
	}
	return oneAway;
}

int main() {
	int arr[] = {30, 15, 60, 75, 45, 15, 15, 45};
	int size = sizeof(arr)/sizeof(arr[0]);
	int maxmin = MaxMinutes(arr, size);
	cout << "maxmin she can handle = " << maxmin << endl;
}
