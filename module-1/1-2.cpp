// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

#include<iostream>
#include<string>
using namespace std;

bool permutation(string s, string t);

bool permutation(string s, string t) {
	if(s.length() != t.length()) {
		return false;
	}
	
	int* letters = new int[256];
	//char* s_array = new int[sizeof(s.lenght()];
	//strcpy(s_array, s.c_str());
	for(int i =0; i < s.length(); i++) {
		int c = s.at(i);
		letters[c]++;
	}

	for(int i = 0; i < t.length(); i++) {
		int c = t.at(i);
		if(letters[c]-- < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	string s = "amd";
	string t = "dma";
	if(!permutation(s, t)) {
		std::cout << "Both are not permutations" << std::endl;
	}
	std::cout << "Both are same" << std::endl;
}
