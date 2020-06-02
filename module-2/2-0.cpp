// single linked list implementation using C and C++ style
#include<iostream>
#include<stdlib.h>
using namespace std;

bool instert(int);
bool print();

typedef struct cNode {
	int data;
	cNode *next = NULL;
} cNode;


cNode *head = NULL;

bool insert(int d) {
	cNode *newcNode = (cNode*) malloc(sizeof(cNode));
	if(head == NULL ) {
		head = newcNode;
		newcNode->data = d;
		return true;
	}
	newcNode->data = d;
//	cNode *tmp = (cNode*) malloc(sizeof(cNode));
	cNode *tmp;
	tmp = head;
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newcNode;
	return true;
}

bool print() {
	if(head != NULL) {
//		cNode *tmp = (cNode*) malloc(sizeof(cNode));
		cNode* tmp = head;
		while(tmp->next != NULL) {
			cout << "out = " << tmp->data << endl;
			tmp = tmp->next;
		}
		cout << "out = " << tmp->data << endl;
	}
	return true;
}

class cppNode {
	int data;
	cppNode *next = NULL;
  public:
	cppNode(int d) {
		data = d;
	}
	bool insert(int d) {
		cppNode *newcppNode = new cppNode(d);
		cppNode *n = this;
		while(n->next != NULL) {
			n = n->next;
		}
		n->next = newcppNode;
	}
};
			
		
int main() {
	int data;
	cout << "Implementing Single Linked List using C and Cpp style" << "C style ...." << endl;
	for(int i = 0; i < 4; ++i) {
		cin >> data;
		insert(data);
	}
	print();
	cout << "Cpp style ..." << endl;
	cin >> data;
	cppNode list(data);
	for(int i = 0; i < 3; ++i) {
		cin >> data;
		list.insert(data);
	}
}
	


