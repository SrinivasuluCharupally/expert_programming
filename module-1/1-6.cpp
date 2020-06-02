//String Compression: Implement a method to perform basic string compression using the counts
//of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
//"compressed" string would not become smaller than the original string, your method should return
//the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

string compress(string);
int lengthCheck(string);


string compress(string str) {
	int l = lengthCheck(str);
	if( l >= str.length()) {
		return str;
	}

	//string* compressed = new string[l];
	string compressed;
	int count = 0;
	for(int i = 0; i < str.length(); ++i) {
		count++;
		if(str.at(i) != str.at(i+1)) {
			compressed += str.at(i);
			//compressed.append(str.at(i));
			compressed += count;
		}
	}
	//compressed += '\0';
	return compressed;
}

int lengthCheck(string str) {
	int length = 0;
	for(int i = 0; i < str.length()-1; ++i) {
		if(str.at(i) != str.at(i+1)) {
			length++;
		}
	}
	return length;
}

int main() {
	string str = "aabbc";
	string compressed = compress(str);
	if(compressed.length() != str.length()) {
		cout << "Compression done" << endl << compressed << endl;
		return 0;
	}
	cout << "Not compressed" << endl;
}
	
