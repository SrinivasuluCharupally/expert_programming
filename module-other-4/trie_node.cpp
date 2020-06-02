// implement trie tree...

// source http://www.geeksforgeeks.org/trie-insert-and-search/

// runtime of search is O(M), where M is max string lengh.

#include<iostream>
#include<string>
#include<stdlib.h> // atoi() is part of it
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
		if(i == k.length()) { return true; }
		else return false;
	}
	

};

	
int main() {
	string s[] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};

	TrieTree tree;
	int size = sizeof(s)/sizeof(s[0]);
	for(int i = 0; i < size; ++i)
		tree.insert(s[i]);
	if(tree.search(s[2]))  cout << "Found" << endl;
	else cout << "Not found " << endl;
}
