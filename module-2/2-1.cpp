// implementing single linked list using cpp style... and remove deplicate elements from the list..
//Remove Dups: Write code to remove duplicates from an unsorted linked list. FOLLOW UP , How would you solve this problem if a temporary bu er is not allowed? 

#include<iostream>
#include<stdlib.h>
using namespace std;

class cppNode {
	cppNode *next = NULL;
	int data;

  public:
	cppNode(int d) {
		data = d;
	}

	bool insert(int d) {
		cppNode *tmp = this;
		cppNode *newcppNode = new cppNode(d);
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newcppNode;
		return true;
	}
	bool print() {
		cppNode *tmp = this;
		while(tmp->next != NULL) {
			cout << "output = " << tmp->data << endl;
			tmp = tmp->next;
		}
                cout << "output = " << tmp->data << endl;
		return true;
	}
	bool delDup() {
		cppNode *current = this;
		cppNode *runner;
		while(current->next != NULL) {
			runner = current;
			while(runner->next != NULL) {
				if(runner->next->data == current->data) {
					//current->next = runner->next;
					if(runner->next->next == NULL) { 	
						runner->next = NULL;
						return true;
					}
					runner->next = runner->next->next;
					//break;
					
				}
				else {
					runner = runner->next;
				}
			}
			current = current->next;
		}
		return true;
	}
};

int main() {
	int data;
	cin >> data;
	cppNode node(data);
	
	for(int i = 0; i < 5; ++i) {
		cin >> data;
		node.insert(data);
	}
	node.print();
//	int *k = new int[10];
//	int *kk = (int*) malloc(sizeof(int) * 10);
	if(node.delDup()) {
		cout << endl << "After listed compressed" << endl;
		node.print();
	}
}

