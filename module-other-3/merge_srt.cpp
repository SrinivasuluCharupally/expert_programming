// merge sort
// source optimized, 
// algorithem : https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm

// source using one more temp buffer... https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_program_in_c.htm


#include<iostream>
using namespace std;

void Merge(int* a, int low, int mid, int high) {

 int b[high];
 int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];

/*

	int left_size = mid - left + 1;
	int right_size = right - mid;

	int left_arr[left_size], right_arr[right_size];

	for(int i = 0; i < left_size; ++i) 
		left_arr[i] = arr[left + i];
	
	for(int i = 0; i < right_size; ++i) 
		right_arr[i] = arr[mid + 1 + i];

	int i = 0, j = 0;
	int k = left;

	while(i < left_size && j < right_size) {
		if(left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i];
			++i;
		}
		else {
			arr[k] = right_arr[j];
			++j;
		}
		++k;
	}

	while(i < left_size) {
		arr[k] = left_arr[i];
		++i;
		++k;
	}


	while( j < right_size) {
		arr[k] = right_arr[j];
		++j; 
		++k;
	}
*/
}

void MergeSort(int* arr, int left, int right) {
	if(left < right) {
		int mid = (left + right )/2;
		MergeSort(arr, left, mid);	
		MergeSort(arr, mid+1, right);
		Merge(arr,left, mid, right);
	}
}

int main() {
	int arr[5] = {1,5,4,9,0};
	int right = sizeof(arr)/sizeof(arr[0]);
	MergeSort(arr,0,right-1);

	for(int i = 0; i < right; ++i )
		cout << arr[i] << endl;

}
