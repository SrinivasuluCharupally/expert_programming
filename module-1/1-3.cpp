//URLi : Write a method to replace all spaces in a string with '%20  You may assume that the string has suf cient space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so that you can perform this operation in place.)


#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

bool repaceSpace(string s);

bool replaceSpace(string s) {
	char* r = new char[sizeof(s.length()) + 4];
	for(int i = 0, k = 0; i < s.length(); ++i) {
		if(s.at(i) == ' ') {
			r[k] = '%';
			r[k+1] = '2';
			r[k+2] = '0';
			k += 3;
		}
		else {
			r[k] = s.at(i);
			++k;
		}
	}
	cout << *r << endl;
	printf("%s\n", r);
	return true;
}

int main() {
	string s = " amd";
	replaceSpace(s);
}

		
