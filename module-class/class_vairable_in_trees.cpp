// this example showcase the power of "this", this is an base, all the incremented vairable will be saved in this, it's kind of base node.
// you should link next node address into this->next, else link will be broken
#include<iostream>
#include<stdlib.h>

using namespace std;

class TreeNode {
	int data;
//	TreeNode* left = NULL;
	TreeNode* next = NULL;
	int size;
	TreeNode* head = NULL;
  public:
	TreeNode(int d) {
		data = d;
		size = 1;
	}

	void Insert(int d) {
		TreeNode* newNode = new TreeNode(d);
		newNode->data = d;
		newNode->size = size;
		if(head == NULL) {head = newNode; this->next = newNode; return;}
		TreeNode* tmp = head;
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		++size;		
	}
	int getSize() {
		return size;
	}
	void Display() {
		TreeNode* tmp = this;
		while(tmp != NULL) {
			cout << "data = " << tmp->data << "seize = " << tmp->size << endl;
			tmp = tmp->next;
		}
	}
};

int main() {
	TreeNode T(10);
	T.Insert(20);
	T.Insert(30);
        T.Insert(30);
        T.Insert(30);

	int size = T.getSize();
//	cout << "seize = " << size << endl;
	T.Display();
}

