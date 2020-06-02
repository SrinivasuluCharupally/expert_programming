// dfs - Tree, recursive.

// inorder -> left - root - right
// preorder > root - left - right
// prost    > left - right - root

// source http://www.geeksforgeeks.org/?p=618 
// DFS for tree explained here: https://www.geeksforgeeks.org/bfs-vs-dfs-binary-tree/

#include<iostream>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
  TreeNode() : left(NULL), right(NULL) {}
};

class CreateTree{
	TreeNode* root;
  public:
	CreateTree() : root(NULL) {}
	void insert(int d){
		root = insertintotree(root, d);
	}

	TreeNode* insertintotree(TreeNode* root, int d) {
		if(root == NULL) {
			TreeNode* newNode = new TreeNode;
			newNode->data = d;
			return newNode;
		}

		else { if(d < root->data) {
				root->left = insertintotree(root->left,d);
			}
			else root->right = insertintotree(root->right,d);
		}
		return root;
	}
	
	void dfsInorder() {
		inorderDisplay(root);
	}

	void inorderDisplay(TreeNode* root) {
		if(root == NULL) return;
		inorderDisplay(root->left);
		cout << root->data << " ";
		inorderDisplay(root->right);
	}
	

	void dfsPreorder() {
		preorderDisplay(root);
	}
	void preorderDisplay(TreeNode* root) {
		if(root == NULL) return;
		cout << root->data << " ";
		preorderDisplay(root->left);
		preorderDisplay(root->right);
	}

	void dfsPostorder() {
		postorderDisplay(root);
	}

	void postorderDisplay(TreeNode* root) {
		if(root == NULL) return;
		postorderDisplay(root->left);
		//cout << root->data << " ";
		postorderDisplay(root->right);
		cout << root->data << " ";
	}
	
};

int main() {

        int arr[7] = {4, 5, 1, 7, 3,0,5};
	CreateTree tree;
	for(int i = 0; i < 7; ++i) 
		tree.insert(arr[i]);
	
cout << "Inorder" << endl;	tree.dfsInorder(); cout << endl;
cout << "Preorder " << endl;	tree.dfsPreorder(); cout << endl;
cout << "Postorder" << endl;	tree.dfsPostorder(); cout << endl;
}	
