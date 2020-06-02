//Palindrome Permutation: Given a string, write a function to check if it is a permutation of
//a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
//permutation is a rearrangement of letters. The palindrome does not need to be limited to just
//dictionary words.
//EXAMPLE
//Input: Tact Coa
//Output: True (permutations: "taco cat'; "atc o eta·; etc.)


//Create a bit vector for the string. For each letter with value i, toggle the *ith bit. int 
//boolean isPermutationOfPalindrome(String phrase) {//int bitVector = createBitVector(phrase);
//return bitVector == 0 I I checkExactlyOneBitSet(bitVector);}

//createBitVector(String phrase) { 
//int bitVector = 0; 
//for (char c : phrase.toCharArray()) { 
//int x = getCharNumber(c); 
//bitVector = toggle(bitVector, x); }
//return bitVector; }

17 /* Toggle the ith bit in the integer. */ 
//int toggle(int bitVector, int index) { 
 //if (index< 0) return bitVector; 
//int mask= 1 << index; 
//if ((bitVector & mask) 
//bitVector I= mask; } 
//else { bitVector &= ~mask; }
//return bitVector;t }

/* Check that exactly one bit is set by subtracting one from the integer and * ANDing it with the original integer. */
//boolean checkExactlyOneBitSet(int bitVector) { 
//return (bitVector & (bitVector -1)) == 0; }




#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

bool isPermutationOfPalindrome(string);
int* createTable(string);
bool checkTable(int*);
int totalChar=0;

bool isPermutationOfPalindrome(string s) {
	int* table = createTable(s);
	return checkTable(table);
}

int* createTable(string s) {
	int* table = new int[26];
	for(int i = 0; i < s.length(); ++i) {
		int c = s.at(i) - 'a';
		if(c >= 0 ) {
			table[c]++;
                    totalChar++;
		}
	}
	return table;
}

bool checkTable(int* table) {
      if(totalChar%2 == 0) return false;
	bool found = false;
	for(int i = 0; i < 26; ++i) {
		if(table[i] % 2 == 1) {
			if(found) {
				return false;
			}
			found = true;
		}
	}
	return true;
}
	
int main() {
	string s = "ata";
	if(!isPermutationOfPalindrome(s)) {
		cout << "Not a Palandrom " << endl;
		exit(0);
	}
	cout << "Can be Palandrome" << endl;

}
