// Word Frequencies: Design a method to find the frequency of occurrences of any given word in a book. What if we were running this algorithm multiple times?

// logic using stl : https://stackoverflow.com/questions/9462169/increase-values-in-map

// source http://www.geeksforgeeks.org/find-the-k-most-frequent-words-from-a-file/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;

int main() {

	FILE* fp = fopen("input_file.txt", "r");
	char c_string[26];
	map<string, unsigned int> mymap;
	while(fscanf(fp, "%s", c_string) != EOF) {
		string buffer(c_string);
		mymap[buffer] += 1;
	}
	for(map<string, unsigned int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
		cout << itr->first << " " << itr->second << endl;

}
	
