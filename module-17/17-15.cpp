//  Longest Word: Given a list of words, write a program to find the longest word made of other words in the list.

// source book

// runtime of map.find() is O(log n)

// total runtime of the algo is O(m) worst case, m = total no of char in string array... . m = s[0].length + s[1].length + ...

#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

map<string, bool> mymap;

string FindLongWord(string* s, int size, map<string,bool> mymap) {
	for(int i = size-1; i>= 0; --i) {
		//cout << i << endl;
		for(int j = 1; j < s[i].length(); ++j){
			string left = s[i].substr(0,j);
			string right = s[i].substr(j,(s[i].length()-j));

			map<string,bool>::iterator itr = mymap.find(left);

			if(itr != mymap.end()) {
	                        map<string,bool>::iterator itr1 = mymap.find(right);	
				if(itr1 != mymap.end())
				 return s[i];
			}

		}
	}
	
}

int main() {
	 string s[] = {"test", "tester", "testertest", "testing", "testingtester"};
	int size = sizeof(s)/sizeof(s[0]);
	sort(s, s+size);
//	map<string, bool> mymap;
	for(int i =0; i < size; ++i) // insert into map
		mymap.insert(pair<string,bool>(s[i],true));
	for(map<string,bool>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr) // print map elements...
		cout << (itr->first) << endl;

	string longword = FindLongWord(s, size, mymap);
	cout << "Longest word made of other words = " << longword << endl;
}
