// On old cell phones, users typed on a numeric keypad and the phone would provide a list of words that matched these numbers. Each digit mapped to a set of O - 4 letters. Implement an algorithm to return a list of matching words, given a sequence of digits. You are provided a list of valid words (provided in whatever data structure you'd like). The mapping is shown in the diagram below



// source book..

// the below code is for mapping given words into hashtable, seaching words for user input would be very easy

#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;

unordered_multimap<string, string> mymap; // multipmap

void Map() {

}

const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};

int main() {
	string str[] = {"hi", "helo","gi" };
	for(int i = 0; i < 3; ++i) {
		string s;
		for(int j = 0; j < str[i].length(); ++j) {
			int c = (int)(str[i].at(j)) - 97;
			c = c/3+1;
			s += to_string(c); // converting int to string, under #include<string>
		}
		mymap.insert(pair<string,string>(s, str[i]));
	}
	for(auto& x: mymap) 
		cout << x.first << " " << x.second << endl;
}	

