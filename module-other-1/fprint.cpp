#include<iostream>
#include<string.h>
//#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main() {
	FILE *fp = fopen("fprint.txt", "w");
	fprintf(stderr, "%d", 10);
	fprintf(stdout, "%d", 10);
	fprintf(fp, "%d", 10);
}
