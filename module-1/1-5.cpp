//one Away: There are three types of edits that can be performed on strings: insert a character,
//remove a character, or replace a character. Given two strings, write a function to check if they are
//one edit (or zero edits) away.
//EXAMPLE
//pale, ple -> true
//pales, pale -> true
//pale, bale -> true
//pale, bae -> false

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

bool oneEditAwat(string, string);

bool oneEditAway(string first, string second) {
	if(first.length() - second.length() > 1) {
		return false; 
	}

	string s1 = first.length() <= second.length() ? first : second;
	string s2 = first.length() > second.length() ? second : first;
	
	int index1 = 0;
	int index2 = 0;
	bool found = false;
	while(index1 < s1.length() && index2 < s2.length()) {
		if(s1.at(index1) != s2.at(index2)) {
			if(found) {
				return false;
			}
			found = true;			
	             if(s1.length() == s2.length()) {
				index1++;
		        }
               }
		else {
			index1++;
		}
		index2++;
	}
	return true;
}

int main() {
	string s1 = "pale";
	string s2 = "ple";
	if(!oneEditAway(s1, s2)) {
		cout << "3 conditions failed" << endl;
		exit(0);
	}
	cout << "3 conditions Pass" << endl;
}
				
