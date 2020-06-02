//  Pairs with Sum: Design an algorithm to find all pairs of integers within an array which sum to a specified value.


// soruce book, core logic is similar to 16.21

#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> mymap;

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void FindPairs(int* arr, int first, int last,  int sum) {
	if(first == last) return;
	if(arr[first] + arr[last] < sum) {
	        if(first == last) return;
		else { ++first; 
			FindPairs(arr, first, last, sum);
		}
	}

	if(arr[first] + arr[last] == sum) {
		cout << "pair" << arr[first] << " "  << arr[last] << endl;
		++first; --last;
		FindPairs(arr, first, last, sum);
	}
	else if(arr[first] + arr[last] > sum) {
		--last;
                FindPairs(arr, first, last, sum);

		}

}



int main() {
	int arr[] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};
	int size = sizeof(arr)/sizeof(arr[0]);
	qsort(arr, size, sizeof(int), compare);
	FindPairs(arr, 0, size-1, 12);
}
