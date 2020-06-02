// creating binary tree from given arry, with sorted form
//source https://gist.github.com/mycodeschool/10016271
// 				4
//		1				5
//	0		3		5		7
#include<iostream>
using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
} TreeNode;

TreeNode* root = NULL;
TreeNode* Insert(TreeNode* root, int d) {
	if(root == NULL) {
		root = new TreeNode();
		root->data = d;
	}

	else { 
		if(d <= root->data) {
			root->left = Insert(root->left, d);
		}
		else root->right = Insert(root->right,d);
	}
	return root;
}

void DisplayInorder(TreeNode* root) {
	//TreeNode* tmp = root;
	if(root==NULL) return;
//	cout << root->data << " " ;
	DisplayInorder(root->left);
	cout << root->data << " ";
	DisplayInorder(root->right);
}

int main() {
	int arr[7] = {4, 5, 1, 7, 3,0,5};
	for(int i = 0; i < 7; ++i) {
		root = Insert(root, arr[i]);
	}
	cout << " printing data " << endl;
	DisplayInorder(root);
        cout << " printing completed " << endl;

}
	
	
