// Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
//source http://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode*  left = NULL;
	TreeNode* right = NULL;
} TreeNode;

TreeNode* ArrayToTree(int[], int, int);

TreeNode* ArrayToTree(int arr[], int start, int end) {
	if(start > end)  {
		return NULL;
	}
	TreeNode* newNode = (struct TreeNode*) malloc(sizeof(TreeNode));
	int mid = (start+end)/2;
	newNode->data = arr[mid];
	newNode->left = ArrayToTree(arr, start, mid-1);
	newNode->right = ArrayToTree(arr,mid+1, end);
	return newNode;
}

void print(TreeNode* Node) {
	if(Node == NULL) return;
	cout << " " << Node->data;
	print(Node->left);
	print(Node->right);
}

int main() {
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int n = sizeof(a)/sizeof(a[0]);

TreeNode* Tree = ArrayToTree(a, 0, n-1);
print(Tree);
}
