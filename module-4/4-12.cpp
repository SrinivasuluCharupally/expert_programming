// Paths with Sum: You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).


//source http://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
// creating binary tree from given arry using C++ ,

//source http://www.cplusplus.com/forum/beginner/131457/
// 				4
//		1				5
//	0		3		5		7
#include<iostream>
#include<vector>

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
	
	void PrintKPaths(TreeNode* root, int value) {
		vector<int> path;
		PrintKPathsUtil(root, path, value);
	}

	void PrintKPathsUtil(TreeNode* root, vector<int> &path, int value) {
		if(root == NULL) return ;
		path.push_back(root->data);
		PrintKPathsUtil(root->left, path, value);
		PrintKPathsUtil(root->right, path, value);
		int f = 0;
		/*for(int i = 0; i< path.size(); ++i) cout << path[i];
		cout << "one path finished" << endl; */

		for(int j = path.size()-1; j>=0; --j)           
            {
			f += path[j];
			if(f == value) { cout << "printing actual found path = " ; PrintVector(path,j);}
		}
		path.pop_back();
	}
	
	void PrintVector(vector<int>& path, int j) {
		//cout << endl;
		for(int i = j; i < path.size(); ++i) {
			cout << path[i] << " ";
		}
		cout <<  endl;
	}
		
};

int main() {
	int arr[7] = {4, 5, 1, 7, 3,0,5};
	Tree T;
	for(int i = 0; i < 7; ++i) {
		TreeNode* root = T.Insert(T.getroot(), arr[i]);
		T.setroot(root);
	}
	cout << " printing original Tree data " ;
	T.DisplayInorder(T.getroot());
	cout << endl;
	int value = 4;
	T.PrintKPaths(T.getroot(), value);

}
	
	
