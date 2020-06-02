// creating a binary tree based on given arr, this is not sorrted
//source http://stackoverflow.com/questions/28893017/converting-an-array-into-binary-tree-using-c

#include<iostream>
#include<stdlib.h>


using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
} TreeNode;

int i = 0;
TreeNode* BuildTree (int arr[], int start, int end) {
	if(start >= end) return NULL;
	TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->data = arr[start];
	newNode->right = BuildTree(arr, 2*start+1, end);
	 newNode->left = BuildTree(arr, 2*start+2, end); 
	
	return newNode;
}

void DisplayTree(TreeNode* Tree) {
	if(Tree == NULL)return;
	cout << Tree->data ;
	DisplayTree(Tree->left);
	DisplayTree(Tree->right);
}

int main() {
	int arr[3] = {4,5,6};
	TreeNode* Tree = BuildTree(arr,0, 3);
	DisplayTree(Tree);
	cout << endl;
}


