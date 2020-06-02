// binary search without recursion 
// sour ce http://petercrushcode.blogspot.in/2016/06/reading-integer-streams-and-return-n-th.html

#include<iostream>
using namespace std;

typedef struct Node {
	int value;
	Node* left = NULL;
	Node* right = NULL;
} Node;

class Tree {
	Node* root=NULL;
  public:
	void insert(int x) {
		if(root == NULL) {
			root = new Node;
			root->value = x;
			return;
		}
		Node* cur = root;
		Node*  pre  = NULL ;
		while(cur != NULL) {
			pre = cur;
			if(cur->value >= x)
				cur = cur->left;
			else 	cur = cur->right;
		}

		if(pre->value < x) {
		pre->right = new Node;
		pre->right->value = x;	
		}
		else {
			pre->left = new Node;
			pre->left->value = x;
		}
		
	
	}
	void display() {
		Node* cur = root;
		print(cur);		
	}
	void print(Node* cur) {
		if(cur == NULL) return;
		cout << cur->value << endl;
		print(cur->left);
		print(cur->right);
	}
	int height() {
		return findheight(root);
	}
	int findheight(Node* cur) {
		if(cur == NULL) return 0;
		int lheight = findheight(cur->left);
		int rheight = findheight(cur->right);
		if(lheight > rheight) return (lheight+1);
		else return (rheight+1);
	}
};



int main() {
	int arr[9] = { 5, 1, 4, 4,  5,  9, 7, 13, 3};

	Tree tree;
	for(int i =0; i < 9; ++i)
		tree.insert(arr[i]);
	tree.display();
	cout << "height of tree = " << tree.height() << endl;
}

