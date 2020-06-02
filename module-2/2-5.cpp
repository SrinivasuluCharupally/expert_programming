// Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list. 
// EXAMPLE
//	Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
//	Output: 2 -> 1 -> 9. That is, 912.
//	FOLLOW UP
//	Suppose the digits are stored in forward order. Repeat the above problem.
//	Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
//	Output: 9 -> 1 -> 2. That is, 912.

#include<iostream>
using namespace std;

class cppNode {
        int data, data2;
        cppNode *next = NULL;
  public:
        cppNode(int d) {
                data = d;
		data2 = d;
        }
	cppNode(){}
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
                        cout << " output list = " << tmp->data << endl;
                        tmp = tmp->next;
                }
                cout << " output list = " << tmp->data << endl;
	}
	static void add(cppNode* node1, cppNode* node2) {
		cppNode* tmp;
		cppNode* relHeadNode;
		for(int i = 0 ; i < 3; ++i) {
                        cppNode *relNode = new cppNode(node1->data + node2->data);
			if(i == 0) {
				tmp = relNode;
				relHeadNode = relNode;
				node1 = node1->next;
				node2 = node2->next;
				continue;
			}
			
			tmp->next = relNode;
			tmp = relNode;
			node1 = node1->next;
			node2 = node2->next;
		}
		relHeadNode->print();
		//return relHeadNode;
	}
};


int main() {
	cout << "Enter First number " ;
	int data1, data2;
	cin >> data1;
	cout << "Enter Second number ";
	cin >> data2;
	int rel1 = data1 % 10;
	int rel2 = data2 % 10;
	cppNode node1(rel1), node2(rel2), relNode;
	for(int i = data1/10; i > 0; ) {
		rel1 = i % 10;
		i = i / 10;
		node1.insert(rel1);
	}
	for(int i = data2/10; i > 0; ) {
		rel2 = i % 10;
		i = i / 10;
		node2.insert(rel2);
	}
	cout << "First linked list" << endl;
	node1.print();
	cout << "Second linked list" << endl;
	node2.print();
	cout << "Printing addition of two linked list" << endl;
	cppNode::add(&node1, &node2);
//	relHeadNode
	cout << "Size of node1 = " << sizeof(node1) << endl;
	cppNode* test;
	cout << "Size of node pointer  = " << sizeof(test) << endl;
}
