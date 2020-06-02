// Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
// EXAMPLE
//	lnput:the node c from the linked list a->b->c->d->e->f
//	Result: nothing is returned, but the new linked list looks like a ->b->d- >e- >f



#include<iostream>
using namespace std;

class cppNode {
	int data;
	cppNode *next = NULL;
  public:
	cppNode(int d) {
		data = d;
	}
	bool insert(int d) {
		cppNode *newcppNode = new cppNode(d);
		cppNode *tmp = this;
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newcppNode;
		return true;
	}
	void print() {
		cppNode *tmp = this;
		while(tmp->next != NULL) {
			cout << " output = " << tmp->data << endl;
			tmp = tmp->next;
		}
		cout << " output = " << tmp->data << endl;
	}
	bool deleteNode(int dN) {
		cppNode *tmp = this;
		for(int i = 0; i < dN-1; ++i) {
			tmp = tmp->next;
		}
		deleting(tmp);
	}
	bool deleting(cppNode *nodeDel) {
		if(nodeDel == NULL || nodeDel->next == NULL) {
			return false;
		}
		cppNode *tmp = nodeDel->next;
		nodeDel->data = tmp->data;
		nodeDel->next = tmp->next;
		return true;
	}
};

int main() {
	int d;
	cout << " Enter 5 elements" << endl;
	cin >> d;
	cppNode node(d);
	for(int i = 0; i < 4; ++i) {
		cin >> d;
		node.insert(d);
	}
	node.print();
	cout << "Delete one node = " << endl;
	int dN; cin >> dN;
	node.deleteNode(dN);
	node.print();
}
