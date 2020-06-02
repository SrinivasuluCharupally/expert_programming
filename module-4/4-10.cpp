// construct Tree first, source http://stackoverflow.com/questions/28893017/converting-an-array-into-binary-tree-using-c

// Find T2 is sub tree of T1..
// source http://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	char side;
} TreeNode;


int i = 0;

TreeNode* BuildTree (int arr[], int start, int end) {
	if(start  >= end) {
		return NULL;
	}
	TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->data = arr[start];
	newNode->left = BuildTree(arr, 2*start+1, end);
	newNode->right = BuildTree(arr, 2*start+2, end);

	return newNode;
}

void DisplayTree(TreeNode* Tree) {
	if(Tree == NULL ) return;
	cout << Tree->data << " " ;
	DisplayTree(Tree->left);
	DisplayTree(Tree->right);
}

bool areIdentical(TreeNode* r1, TreeNode* r2) {
	if(r1 == NULL && r2 == NULL) return true;
      //if(r1 == NULL || r2 == NULL) return false

	return (r1->data == r2->data && areIdentical(r1->left, r2->left) && areIdentical(r1->right , r2->right));
}


bool isSubTree(TreeNode* T, TreeNode* S) {
	if(T == NULL && S != NULL)return false;
	if(S == NULL && T != NULL) return true;
	if(areIdentical(T,S)) return true;
	return isSubTree(T->left,S) || isSubTree(T->right,S);

}
		

int main() {
	int arr1[7] = { 26,10,3,4,6,3,30};
	int arr2[4] = { 10,4,6};
	TreeNode* Tree1 = BuildTree(arr1,0,7);
	TreeNode* Tree2 = BuildTree(arr2,0,3);
	cout << " Dispaly Tree1 = " << endl;
	DisplayTree(Tree1);
	cout << endl << "Display Tree2 = " << endl;
	DisplayTree(Tree2);
	cout << endl;
	if(!isSubTree(Tree1,Tree2)) {
		cout << " Is not sub Tree" << endl;
		return 0;
	}
	cout << " Is a Sub Tree" << endl;
	 return 0;
	
//	cout << endl;
//        cout << Tree1->left->left->right->right->data ;
//        cout << Tree2->left->right->right->data;	
}
