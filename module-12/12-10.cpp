// Malloc: Write an aligned malloc and free function that supports allocating memory such that the memory address returned is divisible by a speci c power of two.



// source https://sites.google.com/site/ruslancray/lab/bookshelf/interview/ci/low-level/write-an-aligned-malloc-free-function

// source for class type: http://www.cnblogs.com/grandyang/p/4932046.html


#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void* aligned_malloc(size_t required_bytes, size_t alignment) {
	void* p1;
	void** p2;
	int offset = alignment -1;
	p1 = (void*)malloc(required_bytes + offset);
	if(p1 == NULL) return NULL; // no memory available

	p2 = (void**)(((size_t)(p1) + offset) & ~(alignment -1));
	p2[-1] = p1;
	return p2;
}

void aligned_free(void* p) {
	free(((void**)p)[-1]);
}

int main() {
	int *p = (int*)aligned_malloc(100, 16);	
	cout << "16 bit alignment address = " << p ; 
//	printf("%p" , p);
	cout << endl;
}