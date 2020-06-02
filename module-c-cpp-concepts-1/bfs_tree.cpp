// creating tree from given array and do DFS , depth first search

// source http://www.geeksforgeeks.org/?p=2686

#include<iostream>
using namespace std;

class TreeNode{
 public:
	int data;
	TreeNode *left;
	TreeNode *right;
//  public:
	TreeNode() : left(NULL), right(NULL) { }
};

class CreateTree {
	TreeNode* root;
  public:
	CreateTree() : root(NULL) {}

	void insert(int d) {
		root = insertintotree(root,d);
	}

	TreeNode* insertintotree(TreeNode* root, int d) {
		if(root == NULL) {
			TreeNode* newNode = new TreeNode;
			newNode->data = d; 
		//	root = newNode; // i fyou do this then it willl not work because initially root = 0x0 so it becomes local will not assign to class->root, you should return the address then shotre into root...
			return newNode;
		}

		if(d < root->data) {
			root->left = insertintotree(root->left, d);
		}
		else  root->right = insertintotree(root->right, d);
		return root; // carefull, you should return root address all the time same, so it requires....
	}

	void displayTree() {
		Display(root);
	}

	void Display(TreeNode* root) {
		if(root == NULL) return;
		cout << root->data << " " ;

		Display(root->left);
		Display(root->right);
	}

	int height(TreeNode* root) {
		if(root == NULL) return 0 ;
		else { 
			int lheight = 	height(root->left);
			int rheight = height(root->right);
			if(lheight>rheight) return lheight+1;
			else return rheight+1;
		}
	}
	
	void bfsDisplay(TreeNode* root, int level) {
		if(root == NULL) return;
		if(level == 1) cout << root->data;
		else { if(level > 1) {
				bfsDisplay(root->left, level-1);
				bfsDisplay(root->right, level-1);
			}
		}
	}

	void BFS() {
		int height1 = height(root); // height is mandate in BFS, because we have to print all elements in each level...
	cout << endl;
	for(int i =1; i <= height1; ++i) {
		bfsDisplay(root, i); cout << endl;
	}
	}


};




int main() {
	int arr[7] = {4, 5, 1, 7, 3,0,5};
	CreateTree tree;
	for(int i =0; i < 7; ++i) 
		tree.insert(arr[i]);

	tree.displayTree();
	tree.BFS();
}


