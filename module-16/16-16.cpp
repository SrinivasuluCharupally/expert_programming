// finding unsorted array in given long array..

// source book
#include<iostream>
using namespace std;

typedef struct unsorted {
	int min;
	int max;
} unsorted_t;

unsorted_t Findingunsorted(int* arr, int size) {
	unsorted_t rel;
//	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 1; i < size; ++i) {
		if(arr[i-1] > arr[i]) {
 			rel.min = i+1;
			break;
		}
	}
	for(int i = size-1; i >=0; --i) { 
		if(arr[i-1] > arr[i]) {
			rel.max = i-1;
			break;
		}
	}
	int tmp_max = rel.max;
	while(arr[tmp_max] > arr[rel.max+1]) { rel.max +=1;} 

	return rel;
}


int main() {
	int arr[] = {1, 2, 4, 7, 10, 11, 8,3, 5, 7,  12, 5, 6, 16, 18, 19};
        int size = sizeof(arr)/sizeof(arr[0]);
	unsorted_t result = Findingunsorted(arr, size);
	cout << "Min = " << result.min << "Max = " << result.max << endl;
}
