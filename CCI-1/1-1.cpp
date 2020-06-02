//Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

//The time complexity for this code isO(n), where n is the length of the string. The space complexity isO(l)

//optimised :without much space
//bool isUnique(string str) {
    //if(str.length() > 256) return false;

    //int checker =0;
    //cout << str.length() << endl;
    //for (int i = 0; i < str.length(); i++) {
        //int val = str.at(i);
        //if((checker & (1<<val)) > 0)
            //return false; }
        //checker |= (1 << val);
        //cout << char_set[val]  << " " << val << endl;
    }
    //return true;


#include<iostream>
#include<string>

using namespace std;

bool isUnique(string str);

bool isUnique(string str) {
	if(str.length() > 256) return false;

	bool* char_set = new bool[256];
	cout << str.length() << endl;
	for (int i = 0; i < str.length(); i++) {
		int val = str.at(i);
		if(char_set[val]) {
			return false; }
		char_set[val] = true;
		cout << char_set[val]  << " " << val << endl;
	}
	return true;
}


int main() {
string s = "amdgpu.bdpm=0 amdgpu.powerplay=0 amdgpu.cg_mask=0 amdgpu.pg_mask=0";
isUnique(s);
}

