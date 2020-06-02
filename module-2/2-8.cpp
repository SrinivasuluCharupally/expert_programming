// Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop. 
// DEFINITION: Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
// EXAMPLE
//	Input: A - > B - > C - > D - > E - > C [the same C as earlier]
//	Output: C

// source http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

#include<iostream>
#include<stdlib.h>
using namespace std;

class cppNode {
	cppNode *next = NULL;
public:	int data;

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
		int count = 0;
		while(tmp->next != NULL && count < 10) {
			cout << "output = " << tmp->data << endl;
			tmp = tmp->next;
			++count;
		}
                cout << "output = " << tmp->data << endl;
		return true;
	}
	bool createLoop() {
		cppNode *current = this;
		cppNode *runner;
		while(current->next != NULL) {
			runner = current;
			while(runner->next != NULL) {
				if(runner->next->data == current->data) {
					//current->next = runner->next;
					if(runner->next->next == NULL) { 	
						runner->next = current;
						return true;
					}
					
				}
				else {
					runner = runner->next;
				}
			}
			current = current->next;
		}
		return true;
	}
	cppNode* findLoopNode() {
		cppNode* head = this;
		cppNode* runner = this;
		cppNode* doublerunner = this;
		while(doublerunner->next != NULL) {  // method#1
			cout << " check " << runner->data << " == " << doublerunner->data <<endl;
			runner = runner->next;
			doublerunner = doublerunner->next->next;
			if(runner == doublerunner) { return removeLoop(runner, doublerunner, head);  }
		}
	}


	cppNode* removeLoop(struct cppNode *slow, struct cppNode* fast, struct cppNode *head) {

      slow = head; 
      while(slow->next ! = fast->next) { 
            slow = slow->next;
            fast = fast->next;
      }
        fast->next = NULL;
/*
	   cppNode *ptr1;
	   cppNode *ptr2;
 
	   ptr1 = head;
	   while (1)   {
	     ptr2 = loop_node;
		     while (ptr2->next != loop_node && ptr2->next != ptr1)
		         ptr2 = ptr2->next;
	     if (ptr2->next == ptr1)
        	break;
	     ptr1 = ptr1->next;
   	}
 
	   ptr2->next->next->next = NULL; // removing loop
	   return ptr1; // returning loop node...
	}
	*/
     return head;
};

int main() {
	int data;
	cin >> data;
	cppNode node(data);
	
	for(int i = 0; i < 8; ++i) {
		cin >> data;
		node.insert(data);
	}
	node.print();
	if(node.createLoop()) {
		cout << endl << "After loop created " << endl;
		node.print();
	}
	cppNode* loopNode = node.findLoopNode();
	cout << "Loop at = " << loopNode->data;
	
}

