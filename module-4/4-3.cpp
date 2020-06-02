// List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
//source http://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
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

int PushLevelToNodes(TreeNode* Node) {
	if(Node == NULL) return 0;
//	ArrayOfNodes[Nodecount].push_back(Node->data);
//	++Nodecount;
	else {
		int lheight = PushLevelToNodes(Node->left);
//	Nodecount = 1;
		int rheight = PushLevelToNodes(Node->right);
		if(lheight > rheight) {
			ArrayOfNodes[lheight].push_back(Node->data);
			return (lheight + 1);
		}
		else {
			ArrayOfNodes[rheight].push_back(Node->data);
			return (rheight + 1);
		}
	}
}
	

void displayArray() {
	for(int i = 0; i < 4; ++i) {
		list<int> tmp = ArrayOfNodes[i];
		while(!tmp.empty()) {
			cout << tmp.back() ;
			tmp.pop_back();
		}
		cout << endl;
	}
}
	

int main() {
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int n = sizeof(a)/sizeof(a[0]);

TreeNode* Tree = ArrayToTree(a, 0, n-1);
print(Tree);
PushLevelToNodes(Tree);
cout << " Height of Tree = " << height(Tree) << endl;
displayArray();
}
