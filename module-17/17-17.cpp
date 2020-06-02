// design a method to search in big string for each small string in T. we have to use trietree for all small strings...

// runtime of search is int trietree is O(M), where M is max string lengh.

// The total time to solve the question is O(kt + bk). k is the length of the longest string in T, b is the length of the bigger string, and t is the number of smaller strings within T.

#include<iostream>
#include<string>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

class TrieNode {
  public:
	TrieNode* child[26]; // 26 subnode for every root..
	bool isLeaf;
  TrieNode() {
	for(int i = 0; i < 26; ++i)
		child[i] = NULL;
	isLeaf = false;
	}
};

class TrieTree {
	TrieNode* root;
  public:
	TrieTree() : root(NULL) { }

	void insert(string k) {
		root = insertintoTree(root, k);
	}

	TrieNode* insertintoTree(TrieNode* root, string k) {
		if(root == NULL) {
		root = new TrieNode; }

		TrieNode* construct = root;
		for(int i = 0; i < k.length(); ++i) {
		//	const char* c = &k.at(i); 
		// 	int index = atoi(c); // atoi is for converting '2' into int 2, not for 'a' to 96;
			int index = (int)k.at(i) - 97; // atoi() takes only const char* so you have convert to, &k.at(i);
			if(construct->child[index]==NULL) {
				construct->child[index] = new TrieNode;
			}
			construct = construct->child[index];
		}
		root->isLeaf = true;
		return root;
	}

	bool search(string k) {
		return searchTheTree(root, k);
	}

	bool searchTheTree(TrieNode* root, string k) {
		TrieNode* search = root;
		int i;
		for(i = 0; i < k.length(); ++i) {
//			const char* c = &k.at(i);
			int index = (int)k.at(i) - 97;
			if(search->child[index] == NULL)
				return false;
			search = search->child[index];
		}
		if(i == k.length()) { return true; } // this is only for finding full string match but now we have to find substring which is part of big string...
		else return false;
	}

	bool FindAllStringsInBigString(string big) { // return true if all found...
		for(int i = 0; i < big.length(); ++i) {
			int k = i; int noofchar=1;
			while(k < big.length()) {
			string sub = big.substr(i, noofchar);
			noofchar++; ++k;
			search(sub); // seems to ba big in the implementation, once a string is found the counter should restart from that index
			}
		}
	}
};

	
int main() {
	string big = {"missisippi"};  // this is the big string
	string small[] = {"is", "ppi", "hi", "sis", "i", "ssippi"};

	TrieTree tree;
	int size = sizeof(small)/sizeof(small[0]);
	for(int i = 0; i < size; i++)
		tree.insert(small[i]);

	FindAllStringsInBigString(big); // use question 17-15 method for best results, left & right word...
		
}
