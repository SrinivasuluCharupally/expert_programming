// 20 Alloc: Write a function in C called my2DA1loc which allocates a two-dimensional array. Minimize the number of calls to malloc and make sure that the memory is accessible by the notation arr [ i] [ j].


// source book

#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
T** Allocate2DMemory(T row, T col) {
	T** ptr2D = (T**)malloc( (row*sizeof(T*)) + row*col*sizeof(T));
	T* buf = (T*)(ptr2D + row);
	for(int i = 0; i < row; ++i )
		ptr2D[i] = buf + i*col;

	return ptr2D;
}


int main() {
	int** p = Allocate2DMemory<int>(2,3);
}
