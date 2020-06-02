//  Pond Sizes: You have an integer matrix representing a plot of land, where the value at that location represents the height above sea level. A value of zero indicates water. A pond is a region of water connected vertically, horizontally, or diagonally. The size of the pond is the total number of connected water cells. Write a method to compute the sizes of all ponds in the matrix.


#include<iostream>
using namespace std;
int count=0;
int  FindAPond(int (*arr)[4], int row, int col) {
	if(row ==4 || col ==4 || row <0 || col < 0) return 0 ;

	if(arr[row][col] != 0) return 0 ;
	else { count += 1; arr[row][col] = -1;
	FindAPond(arr, row+1, col);
	FindAPond(arr, row, col+1);
       FindAPond(arr, row+1, col-1);
	FindAPond(arr, row+1, col+1);
       FindAPond(arr, row-1; col-1;)
	}
}

void FindAPondFun(int (*arr)[4], int row, int col) {
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j) {
			if(arr[i][j] == 0) { 
				FindAPond(arr,i,j);
		               cout << "count = " << count << endl;
                		count = 0;
			}
		}		

}

int main() {
	int arr[][4] = {{0,2,1,0},
			{0,1,0,1},
			{1,1,0,1},
			{0,1,0,1}};

	FindAPondFun(arr, 4,4);
	cout << "count = " << count << endl;
}
