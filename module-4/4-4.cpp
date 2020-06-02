// Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.

//source http://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

// for conveting negetive to positive, use abs(min-max)
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
	int mid = (end+start)/2;
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

int height(TreeNode* Node) {
	if(Node == NULL) {
		return 0;
	}
	else {
		int lheight = height(Node->left); 
		int rheight = height(Node->right);
		if(lheight > rheight) {
			return (lheight+1);
		}
		else {
			return (rheight+1);
		}
	}
}

int isBalanced(TreeNode* Node) {
        if(Node == NULL) {
                return 0;
        }
        else {
                int lheight = isBalanced(Node->left);
              	// if(lheight == 0) return -1;
                int rheight = isBalanced(Node->right);
		// if(rheight == 0) return -1;
                if(abs(lheight - rheight) > 1) {
                        return -1;
                }
                else {
                        return (lheight > rheight ? (lheight+1) : (rheight+1));
                }
        }
}




int main() {
//int a[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14, 15};
int a[10] = {1,2,3,4,5,6,7,8,9,10};

int n = sizeof(a)/sizeof(a[0]);

TreeNode* Tree = ArrayToTree(a, 0, n-1);
print(Tree);
cout << " Height of Tree = " << height(Tree) << endl;
if(isBalanced(Tree) == -1) { 
	cout << " Not a balance" << endl;
	return 0;
}
cout << " Is balanced Tree" << endl;
}
