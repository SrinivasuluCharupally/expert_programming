// pick a random node from entire binary tree
// suorce==  book, this is not implemented because it's simple , you have  to use "size" of node
// creating binary tree from given arry using C++ , with sorted form, source https://gist.github.com/mycodeschool/10016271
// 				4
//		1				5
//	0		3		5		7
#include<iostream>
using namespace std;


class TreeNode {
public:
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	int size ;
	
};

class Tree {
	TreeNode* root = NULL;

  public:
	TreeNode* getroot() {
		return root;
	}
	void setroot(TreeNode* r) {
		root = r;
	}
	

	TreeNode* Insert(TreeNode* root, int d) {
		if(root == NULL) {
			root = new TreeNode;
			root->data = d;
		}
		else {
			if(d <= root->data) {
				root->left  = Insert(root->left,d);
			}	
			else {
				root->right = Insert(root->right,d);
			}
		}
		return root;
	}

	void DisplayInorder(TreeNode* root) {
		if(root == NULL) return;
		DisplayInorder(root->left);
		cout << root->data << " ";
		DisplayInorder(root->right);
	}
};

int main() {
	int arr[7] = {4, 5, 1, 7, 3,0,5};
	Tree T;
	for(int i = 0; i < 7; ++i) {
		TreeNode* root = T.Insert(T.getroot(), arr[i]);
		T.setroot(root);
	}
	cout << " printing data " << endl;
	T.DisplayInorder(T.getroot());
        cout << " printing completed " << endl;

}
	
	
