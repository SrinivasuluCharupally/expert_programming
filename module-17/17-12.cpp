// BiNode: Consider a simple data structure called BiNode, which has pointers to two other nodes. The data structure BiNode could be used to represent both a binary tree (where node1 is the le  node and node2 is the right node) or a doubly linked list (where node1 is the previous node and node2 is the next node). Implement a method to convert a binary search tree (implemented with BiNode) into a doubly linked list. The values should be kept in order and the operation should be performed in place (that is, on the original data structure).

// it is nothing but inorder DFS tree

// source https://mcodegeeks.com/binode-binary-search-tree-doubly-linked-list/

#include<iostream>
using namespace std;


class BiNode {
 public:
	int data;
	BiNode* node1;
	BiNode* node2;
  public:
	BiNode(int d=0) : data(d) { 
		node1 = NULL;
		node2 = NULL;
	}
};

BiNode* convert(BiNode* root) {
	if(root == NULL) return NULL;
	BiNode* node1 = convert(root->node1);
	BiNode* node2 = convert(root->node2);
	
	if(node1) {
		BiNode* tail = node1;
			while(tail->node2)
				tail = tail->node2;
		
             tail->node2 = root;
		root->node1 = tail;
	}

	if(node2) {
		root->node2 = node2;
		node2->node1 = root;
	}

	return node1 ? node1 : root;
}


int main(int argc, char** argv)
{
	BiNode* tree = new BiNode(4);
	tree->node1 = new BiNode(2);
	tree->node1->node1 = new BiNode(1);
	tree->node1->node1->node1 = new BiNode(0);
	tree->node1->node2 = new BiNode(3);
	tree->node2 = new BiNode(5);
	tree->node2->node2 = new BiNode(6);
 
	BiNode* list = convert(tree);
	BiNode* iter = list;
	while(iter)
	{
		std::cout << iter->data << " ";
		iter = iter->node2;
	}
	std::cout << std::endl;
	return 0;
}
