// linear search
// source : https://www.geeksforgeeks.org/linear-search/

#include<iostream>
using namespace
int main() {
	int arr[] = {4, 2, 6, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int pos=search(arr, size, 6);;
	if(pos) cout << "Position = " << 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}