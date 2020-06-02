// First Common Ancestor: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.


// in case p, q nodes exist with in the tree then solution #1 is good, from book
// in case p or q does not exist in the three then solutiion is #4

// source code http://stackoverflow.com/questions/1484473/how-to-find-the-lowest-common-ancestor-of-two-nodes-in-any-binary-tree


#include<iostream>
#include<list>
#include<stdlib.h>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
} TreeNode;


TreeNode* ArrayToTree(int arr[], int start, int end) {
	if(start > end) {
		return NULL;
	}

	TreeNode* newNode = (TreeNode*) malloc (sizeof(TreeNode));
	int mid = (start + end) /2;
	newNode->data = arr[mid];
	newNode->left = ArrayToTree(arr, start, mid-1);
	newNode->right = ArrayToTree(arr, mid+1, end);
	return newNode;
}

void DisplayTree(TreeNode* Tree) {
	if(Tree == NULL) return;
	cout << Tree->data << " " ;
	DisplayTree(Tree->left);
	cout << endl;
	DisplayTree(Tree->right);
	//cout << endl;
}

TreeNode* FindAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(!root) return NULL;
	if(root == p || root == q) {
		return root;
	}
	else {
		TreeNode* l = FindAncestor(root->left, p , q);
		TreeNode* r = FindAncestor(root->right, p, q);
		if(l && r) {
			return root;
		}
		else { 	if(l) return l;
		     	else return r;
		}
	}
}

int main() {

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int size = sizeof(arr)/sizeof(arr[0]);
TreeNode* Tree = ArrayToTree(arr, 0, size-1);
DisplayTree(Tree);
TreeNode* Ancestor = FindAncestor(Tree, Tree->left->right, Tree->right->left->right);
cout << "Ancestor" << Ancestor->data << endl;
}

