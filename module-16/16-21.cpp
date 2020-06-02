// swapping two numbers to make two arrays's sum equal 

// source book
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int size1, size2;
typedef struct set {
	int element1;
	int element2;
} set_t;

int Sum(int* input, int size) {
	int sum=0;
	for(int i = 0; i < size; ++i) sum += input[i];
	return sum;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}



void FindSet(int* input1, int* input2) {
	int sum1 = Sum(input1, size1);
	int sum2 = Sum(input2, size2);
	int target = (sum1 - sum2)/2;
       qsort(input1, size1, sizeof(input1[0]), compare);
    qsort(input2, size2, sizeof(input2[0]), compare);
       int a=0;
       int b = size2-1;
       while (a < size1 && b > 0) {
          int difference = input1[a] - input2[b];
          if (difference == target) {
                set_t values = {arrayl[a], array2[b]};
                return values;
         } else if (difference < target) {
                      a++;  
                     } else {
                     b--;
                     } } return null;
        }



	
int main() {
	int input1[]  = {4, 1, 2, 1, 1, 2};
	int input2[] = {3, 6, 3, 3};
	size1 = sizeof(input1)/sizeof(input1[0]);        
	size2 = sizeof(input2)/sizeof(input2[0]);

	FindSet(input1, input2);
}
	
