// finding all possible ways of represending $ pennis in 25, 10, 5,  1
// source similar to 8-1

#include<iostream>
using namespace std;

int FindingWays(int*, int);


int FindingWays(int* mem, int count) {
	if(count < 0) return 0;
	if(count == 0) return 1;
	if(mem[count] > -1) return mem[count];
	else {
		mem[count]= FindingWays(mem, count-25) + FindingWays(mem, count-10) + FindingWays(mem, count-5) +FindingWays(mem, count-1);
	}

	return mem[count];
}

int main() {
	int count = 5;
	int *mem = new int[count];
	for(int i =0; i < count; ++i) 
		mem[i] = -1;

	int ways = FindingWays(mem, count);
	cout << "No of ways of given money = " << ways << endl;
}


