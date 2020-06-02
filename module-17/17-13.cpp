// re space, long string dividing into wordds & find the no of char which are not in the dictonary

// source book

// runtime O(n2) worst case & O(n) bestcase


#include<iostream>
#include<string>
using namespace std;

string dictonary[] = {"this", "is" };

bool FoundInDictonary(string substring) {
	for(int i = 0; i < 2; ++i) 
		if(dictonary[i] == substring) return true;

	return false;
}

int SplitToWords(string s) {
	int unknowchar = 0;
	for(int i =0; i <8; ) {
		int noofchar = 1, j = i;
		while(j<=8) {
			string substring = s.substr(i, noofchar);
			if(FoundInDictonary(substring)){
				i = j+1; noofchar = 0;
			}
			j++; ++noofchar;
		}
		if(i+1 != j ) unknowchar++;		
		i++;
	}

	return unknowchar;	
}

int main() {
	string s = "thisisbo";
	int unknowchar = SplitToWords(s);
	cout << "unknow chars in the string is " << unknowchar << endl;
}
