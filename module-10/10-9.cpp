// Sorted Matrix Search: Given an M x N matrix in which each row and each column is sorted in ascending order, write a method to  find an element.

// source .. http://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

// for binary search method , use book


#include<iostream>
using namespace std;

void search(int (*mat)[4], int size, int find_element) {
	int row=0, col = size-1;
	while(row < 4 && col >=0) {
		if(mat[row][col] == find_element) {
			cout << "Found here " << row << " " << col << endl;
			return ;
		}

		if(mat[row][col] < find_element)
			row++;
		else if(mat[row][col] > find_element)
			col--;
	}
	cout << "Element not found" << endl;
}

int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  search(mat, 4, 29);
  return 0;
}
