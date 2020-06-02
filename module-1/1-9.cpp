
// String Rotation: Assume you have a method i 5Su b 5 tr ing which checks if one word is a substring of another. Given two strings, s1 & s2 . write code to check if s2 is a rotation of s1 using only one call to iss isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat"). 

#include<iostream>
#include<string>

using namespace std;

bool isRotation(string, string);
bool isSubstring(string, string);

bool isRotation(string s1, string s2) {
	if((s1.length() == s2.length()) && s1.length() > 0) {
	string s1s1 = s1 + s1;
	return isSubstring(s1s1, s2);
	}
	return false;
}

bool isSubstring(string s1s1, string s2) {
	for(int i = 0; i < s2.length(); ++i) {
		if(s1s1.compare(i, s2.length(), s2) !=0) {
			continue;
		}
		else {
			return true;
		}
	}
	return false;
}


int main() {
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	if(!isRotation(s1, s2)) {
		cout << "Not sub string" << endl;
		return 0;
	}
	cout << "S2 is substring of S1" << endl;
}



