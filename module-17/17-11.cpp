// Word Distance: You have a large text file containing words. Given any two words, find the shortest distance (in terms of number of words) between them in the file. If the operation will be repeated many times for the same file (but di erent pairs of words), can you optimize your solution?


// source

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main() {
	FILE* fp = fopen("input_file.txt", "r");
	char buffer[26];
	string firstword = "to", secondword = "of";
	int previousdistance=-1, distance=0;
	while(fscanf(fp, "%s", buffer) != EOF) {
		string s(buffer);
		if(s == firstword) {
			distance=0;
		}
		else { 
                   if(s != secondword) {
				++distance;
			}
		      else { 
                     if(previousdistance == -1 )         
                      previousdistance=distance;
		        else 
                       if(previousdistance >distance) 
                    previousdistance = distance;
			}
		}
	}

	cout << "shortest disance = " << previousdistance << endl;
}
