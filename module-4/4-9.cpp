// BST Sequences: A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary search tree with distinct elements, print all possiblearrays that could have led to this tree.
//	EXAMPLE
//	Input:
//		2
// 	      1    3
//	Output: {2, 1, 3}, {2, 3, 1}

//printing all tree combinations... of given array
//source http://www.geeksforgeeks.org/find-all-possible-trees-with-given-inorder-traversal/

#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
} TreeNode;

int i = 0;
TreeNode* BuildTree (int arr[], int size) {
	if(i == size) return NULL;
	TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->data = arr[i];
	++i;
	if(arr[i-1] < arr[i]) {
		newNode->right = BuildTree(arr, 3);
	}
	else { newNode->left = BuildTree(arr, 3); }
	
	return newNode;
}

void DisplayTree(TreeNode* Tree) {
	if(Tree == NULL)return;
	cout << Tree->data ;
	DisplayTree(Tree->left);
//	cout << endl;
	DisplayTree(Tree->right);
}

vector<TreeNode*> FindAllTrees(int arr[], int start, int end) {
	vector<TreeNode*> Trees;
	if(start > end) {
		//Trees.push_back(NULL);
		return Trees;
	}

	for(int i = start; i <= end; ++i) { // memorize this logic
		vector<TreeNode*> lTrees = FindAllTrees(arr, start, i-1);
		vector<TreeNode*> rTrees = FindAllTrees(arr, i+1, end);
		for(int j = 0; j < lTrees.size(); j++) {
			for(int k = 0; k < rTrees.size(); ++k) {
				TreeNode* newNode = new TreeNode;
				newNode->data = arr[i];
				newNode->left = lTrees[j];
				newNode->right = rTrees[k];
				Trees.push_back(newNode);
			}
		}
	}
	return Trees;
}


int main() {
	int arr[3] = {4,5,6};
	TreeNode* Tree = BuildTree(arr, 3);
//	cout << " check 6 = " << Tree->right->right->data << endl;
	DisplayTree(Tree);
	vector<TreeNode*> Trees = FindAllTrees(arr, 0, 2);
	cout << " printing all combinations" << endl;
	for(int i = 0; i < Trees.size(); ++i) {
		DisplayTree(Trees[i]);
		cout << endl;
	}
}


