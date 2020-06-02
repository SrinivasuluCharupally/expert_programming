// Palindrome: Implement a function to check if a linked list is a palindrome.
// Example
//	Input: 0 - > 1 - > 2 - > 1 - > 0.
// 	Output:  0 - > 1 - > 2 - > 1 - > 0.

// single linked list implementation using C++ style

#include<iostream>
#include<stdlib.h>
#include<vector>
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
		cppNode *n = this;
		while(n->next != NULL) {
			n = n->next;
		}
		n->next = newcppNode;
	}
	void print() {
		cppNode* tmp = this;
		while(tmp->next != NULL) {
			cout << "out list = " << tmp->data << endl;
			tmp = tmp->next;
		}
                cout << "out list = " << tmp->data << endl;
	}

	bool isPalandrome() {
		cppNode* head = this;
		cppNode* runner = this;
		cppNode* doublerunner = this;
		int counter = 0;
		vector<int> front; // this is the key in this example
		while(doublerunner->next != NULL) {
			front.push_back(runner->data);
			runner = runner->next;
			doublerunner = doublerunner->next->next;
			++counter;
		}
		runner = runner->next;
		while(runner->next !=NULL) {
			if(runner->data != front[counter-1]) {
				return false;
			}
			runner = runner->next;
			--counter;
		}	
		return true;
	}
};		

	
			
		
int main() {
	int data;
	cout << "Enter a number to find whether palandrom .... odd count" << endl;
	cin >> data;
	cppNode node(data);
	for(int i = 0; i < 4; ++i) {
		cin >> data;
		node.insert(data);
	}
	cout << "Printing given linked list ..." << endl;
	node.print();
	cout << "Finding palandrome ...." << endl;
	if(!node.isPalandrome()) {
		cout << "Not a palandrome ..." << endl;
		return 0;
	}
	cout << "Is a palandrome" << endl;
}
	


