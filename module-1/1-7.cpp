//Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int* reversMatrix(int*, int);

int* reversMatrix(int* input, int i) {
	int* output = new int[i * i];
	int off = 1, pos = 1;
	for(int li = 0; li < i; ++li) {
		pos = 1;
		for(int lj = 0; lj < i; ++lj) {
			output[pos * i - off ] = input[li * i +lj];
			++pos;
		}
		++off;
	}
	return output;
}

int main() {
	cout << "i = ";
	int i;
	cin  >> i ;
	int* input = new int[i * i];
	for(int li = 0; li < i; ++li) {
		for(int lj = 0; lj < i; ++lj) {
			cin >>	input[li * i + lj] ;
		}
	}
	int* output = reversMatrix(input, i);
        for(int li = 0; li < i; ++li) {
                for(int lj = 0; lj < i; ++lj) {
                        cout <<  output[li * i + lj] ;
                }
		cout << endl;
        }

}

			
		

