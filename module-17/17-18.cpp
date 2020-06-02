// Shortest Supersequence: You are given two arrays, one shorter (with all distinct elements) and one longer. Find the shortest subarray in the longer array that contains all the elements in the shorter array. The items can appear in any order.

// source book

// runtime is O(SB) time, but it now only takes O(B) additional memory. S is smallarr size, B  is Bigarr size..


#include<iostream>
using namespace std;

void FindShortest(int* closure, int bigsize) {
	int start = -1, end = -1;
	for(int i =0; i < bigsize; ++i) {
		if(closure[i] == -1) break;
		int diff = closure[i] - i;
		if(start == -1 || diff < end - start) {
			start = i;
			end = closure[i];
		}
	}

	cout << "start = " << start << "end = " << end << endl;
}

void FindIndex(int* bigarr, int* smallarr, int bigsize, int smallsize) {
	int* closure = new int[bigsize];
	for(int i = 0; i <bigsize; ++i) closure[i] = -1;
	int  allfoundposition = -1;  // this is to track the last possition, we should update closure[] only if all smallarr are found, see book, index 10 is the one having all smallarr element, above that all -1...


	for(int i = 0; i < smallsize; ++i) { // it's not possible if you pass big array here, it's failure store the small array results...
		int max = -1;
		for(int j = bigsize-1; j >= 0; --j) {
			if(bigarr[j] == smallarr[i]) {
				max = j; 
				if(allfoundposition == -1) 
                          allfoundposition = j;
                     }
				
		
			if( allfoundposition >= j && closure[j] < max) 
				closure[j] = max;
		}
	}

	FindShortest(closure, bigsize);
}



int main() {
	int bigarr[] = {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7};
	int smallarr[] = {1,5,9};
	int bigsize = sizeof(bigarr)/sizeof(bigarr[0]);
	int smallsize = sizeof(smallarr)/sizeof(smallarr[0]);
	FindIndex(bigarr, smallarr, bigsize, smallsize);
}

