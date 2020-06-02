// fill array with same element..

#include<iostream>
using namespace std;

int main() {
	int arr[5];
	fill_n(arr, 5, 100);

	for(int i = 0; i < 5; ++i)
		cout << arr[i] << endl;
}
