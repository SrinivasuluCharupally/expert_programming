// Letters and Numbers: Given an array  filled with letters and numbers,  find the longest subarray with an equal number of letters and numbers.

// source 

#include<iostream>
#include<unordered_map>
#include<stdlib.h>
using namespace std;

unordered_map<int, int> mymap;

void FindingLongestArray(char* arr, int size) {
	int acount=0, onecount=0;
	int delta[size];
	for(int i = 0; i < size; ++i) {
		if(arr[i] == 'a') 
			++acount;
		else ++onecount;
		delta[i] = abs(acount - onecount);
	}
	
	int max[2]= {0,0};
	for(int i =0; i <size; ++i) {
		unordered_map<int,int>::iterator itr = mymap.find(delta[i]);
		if(itr == mymap.end()) {
			mymap.insert(pair<int,int>(delta[i], i));
		}
		else {
			int p = mymap.at(delta[i]);
			int distance = i-p;
			
			int longest =  max[1] - max[0];	
			if(distance > longest) {
				max[1] =i;
				max[0] = p;
			}
		}

	}	
	cout << "start  position " << max[0] << " end position " << max[1] << endl;
}



int main() {
      char array[] = {
                'a', 'a', 'a', 'a',
                '1', '1',
                'a',
                '1', '1',
                'a', 'a',
                '1',
                'a', 'a',
                '1',
                'a', 'a', 'a', 'a'
        };
	int size = sizeof(array)/sizeof(array[0]);
	FindingLongestArray(array, size-1);
}
	
