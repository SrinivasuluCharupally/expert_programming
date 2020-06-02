// creating binary tree from given arry using C++ ,
//source http://www.cplusplus.com/forum/beginner/131457/
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
       TreeNode* root;
	for(int i = 0; i < 7; ++i) {
		root = T.Insert(T.getroot(), arr[i]);
		T.setroot(root);
	}
	cout << " printing data " << endl;
	T.DisplayInorder(T.getroot());
        cout << " printing completed " << endl;

}
	
	
