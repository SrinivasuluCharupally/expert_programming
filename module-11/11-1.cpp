// fiding mistakes...
// unsigned int never decrease below zero..
// it should be printed with %d

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main() {
	unsigned i = 100;
	for(i ; i > 0; --i)
		printf("%u \n" , i);
}
