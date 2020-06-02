// initializing all array elements once, with single element

#include<iostream>
using namespace std;

int main() {
	int arr[5] = {2};
	for(int i = 0; i < 5; ++i)
		cout <<  arr[i] << endl;
	cout << " using fill_n() " << endl;
	fill_n(arr, 5, 2);
	for(int i = 0; i < 5; ++i)
		cout << arr[i] << endl;

}
