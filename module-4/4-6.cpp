// Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.

//source for height calculation http://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

// source for succesor is book
//				5
//		2					8
//	1		3		6			9
				
//			    4			7			10

#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode*  left = NULL;
	TreeNode* right = NULL;
	TreeNode* parent = NULL;
} TreeNode;

TreeNode* ArrayToTree(int[], int, int);
//TreeNode* ArrayOfNodes = (struct TreeNode*) malloc(sizeof(TreeNode))[];
list<int> *ArrayOfNodes = new list<int> [5];
int Nodecount = 0;
TreeNode* ArrayToTree(int arr[], int start, int end, TreeNode* parentNode) {
	if(start > end)  {
		return NULL;
	}
	TreeNode* newNode = (struct TreeNode*) malloc(sizeof(TreeNode));
	int mid = (end+start)/2;
	newNode->data = arr[mid];
	newNode->parent = parentNode;
	parentNode = newNode;
	newNode->left = ArrayToTree(arr, start, mid, parentNode);
	newNode->right = ArrayToTree(arr,mid+1, end, parentNode);
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
	cout << " " << Node->data << " parent Node = " << Node->parent << endl;
	print(Node->left);
	print(Node->right);
}


TreeNode* FindNextNode(TreeNode* n) {
	if(n == NULL) {
		return NULL;
	}
	if(n->right != NULL) {
		TreeNode* tmp = n->right;
		while(tmp->left != NULL) {
			tmp = tmp->left;
		}
		return tmp;
	}
	else {
		TreeNode* current = n;
		TreeNode* up = n->parent;
		while(up != NULL && up->left != current) {
			current = up;
			up = up->parent;
		}
		return up;
	}
}



int main() {
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int n = sizeof(a)/sizeof(a[0]);
TreeNode* Tree = ArrayToTree(a, 0, n-1, NULL);
print(Tree);
TreeNode* Node = Tree->right->left->right;
cout << " Node data = " << Node->data;
TreeNode* succesor = FindNextNode(Node);
cout << " Successor data = " << succesor->data << endl;
}
