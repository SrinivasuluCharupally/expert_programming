// Magic Index: A magic index in an array A[ 1.•.n-1] is defined to be an index such that A[ i] = i //  Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.

//source book

#include<iostream>
using namespace std;

int MagicNumber(int array[], int start,  int end) {
	int mid = (end + start)/2;
	if(array[mid] == mid) return mid;
	if(array[mid] < mid) MagicNumber(array, mid, end);
	else if(array[mid] > mid) MagicNumber(array, start, mid);
	//return mid;
}

int main() {
	int array[9] = {-1, 0, 1,2, 3,5,7,9,10};
	int size = 9;
	int result = MagicNumber(array, 0, size);
	cout << " Magic Number is = " << array[result] << " at position " << result << endl;
}
