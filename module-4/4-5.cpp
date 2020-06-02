// Validate BST: Implement a function to check if a binary tree is a binary search tree.

//source for height calculation http://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
// source for BSTsorted() is from book

#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode*  left = NULL;
	TreeNode* right = NULL;
} TreeNode;

TreeNode* ArrayToTree(int[], int, int);
//TreeNode* ArrayOfNodes = (struct TreeNode*) malloc(sizeof(TreeNode))[];
list<int> *ArrayOfNodes = new list<int> [5];
int Nodecount = 0;
TreeNode* ArrayToTree(int arr[], int start, int end) {
	if(start > end)  {
		return NULL;
	}
	TreeNode* newNode = (struct TreeNode*) malloc(sizeof(TreeNode));
	int mid = (end+start)/2;
	newNode->data = arr[mid];
	newNode->left = ArrayToTree(arr, start, mid-1);
	newNode->right = ArrayToTree(arr,mid+1, end);
	return newNode;
}

int height(TreeNode* Node) {
	if(Node == NULL) {
		return 0;
	}
	else {
		int lheight = height(Node->left);
		int rheight = height(Node->right);
		if(lheight > rheight)
			return (lheight+1);
		else return (rheight+1);
	}
}

void print(TreeNode* Node) {
	if(Node == NULL) return;
	cout << " " << Node->data;
	print(Node->left);
	print(Node->right);
}

bool BSTsorted(TreeNode* Node, int Min, int Max) {
	if(Node == NULL) {
		return true;
	}
	if((Min != NULL && Node->data <= Min) || (Max != NULL && Node->data > Max)) {
		return false;
	}
	if((!BSTsorted(Node->left, Min, Node->data)) || (!BSTsorted(Node->right, Node->data, Max))){	
		return false;
	}	
	
	return true;
}


int main() {
int a[10] = {1,2,3,4,5,6,7,8,9,1};
int n = sizeof(a)/sizeof(a[0]);

TreeNode* Tree = ArrayToTree(a, 0, n-1);
print(Tree);
if(!BSTsorted(Tree, NULL, NULL)) {
	cout << " Not a sofrted tree" << endl;
	return 0;
}
cout << " Is a sorted tree" << endl;
}
