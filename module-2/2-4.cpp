//Partition: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
// EXAMPLE
//	Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
//	Output: 3 -> 1 -> 2 -> 5 -> 5 -> 8 ->10


// source http://www.geeksforgeeks.org/partitioning-a-linked-list-around-a-given-value-and-keeping-the-original-order/


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
	cppNode* sort(int check) {
		cppNode* head = this;
		cppNode* tail = this;
		cppNode* node = this;
		cppNode *tmp, *tracktailnode;
		bool tracktail;
		while(node->next != NULL) {
			tmp = node->next;
			if(node->data < check) {
				head->next = node;
				head = node;
			}
			else {
				if(!tracktail) { tracktailnode = node; tracktail = true; }
				tail->next = node;
				tail = node;
			}
			node = tmp;
		}
		tail->next = NULL;
		head->next = tracktailnode;
		return head;
	}
				
};

int main() {
        int d;
        cout << " Enter 7 elements" << endl;
        cin >> d;
        cppNode node(d);
	for(int i = 0; i < 7; ++i) {
		cin >> d;
		node.insert(d);
	}
	node.print();
	cout << "Enter the value to divede list =" ;
	int check; cin >> check;
	cppNode* sorted = node.sort(check);
	node.print();
}
