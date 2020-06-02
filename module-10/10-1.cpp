// Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.

// suorce book

#include<iostream>
using namespace std;


void merge(int[] a, int[] b, int lastA, int lastB) {      int indexA = lastA - 1;      int indexB = lastB - 1;      int indexMerged = lastB + lastA - 1;     while (indexB >= 0) {
         if (indexA >= 0 && a[indexA] > b[indexB]) {
               a[indexMerged] = a[indexA]; //               indexA- -; } 
          else {
                a[indexMerged] = b[indexB];
                indexB--;
           }
           indexMerged--;
}


void DisplayMerged(int* a, int a_size) {
	for(int i = 0; i < a_size; ++i)
		cout << a[i] << endl;
	
}
int main() {
	int a[10] = {1, 5, 9, 10, 15, 20};
	int b[5] = {2,6, 14, 25, 50};

        int a_size = sizeof(a)/sizeof(a[0]);
        int b_size = sizeof(b)/sizeof(b[0]);
        cout << a_size << " " << b_size << endl;
	int a_last_position = 10;
        Merge(a, b, a_size, b_size);
	DisplayMerged(a, a_size);

}
