//MajorityElement:Amajorityelementisanelementthatmakesupmorethanhalfoftheitemsin an array. Given a positive integers array,  nd the majority element. If there is no majority element, return -1. Do this in O(N) time and 0(1) space.


// source book

// runtime O(n)

#include<iostream>
using namespace std;
// int arr[] = {3,1,7,1,3,7,3,7,1,7,7, 7};

int Candidate(int* arr, int size) {
	int count = 0, candidate_ = 0;
        for(int i =0; i < size; ++i) {
		if(count == 0) candidate_ = arr[i];
		if(arr[i] == candidate_) ++count;
		else --count;
	}
	return candidate_;
}

bool Validate(int* arr, int size, int candidate_) {
	int count = 0;
	for(int i =0; i < size; ++i) {
		if(arr[i] == candidate_)
			++count;
	}
	return count > size/2;
}	

void FindCandidate(int* arr, int size) {	
	int candidate_ = Candidate(arr,size);
	if(Validate(arr,size, candidate_)) // just for validation...
		cout << "Most frequent element = " << candidate_ << endl;
}

int main() {
	int arr[] = {3,1,7,1,3,7,3,7,1,7,7, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	FindCandidate(arr,size);
}
