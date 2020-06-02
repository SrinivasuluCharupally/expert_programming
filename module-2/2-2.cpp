/// @brief: Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list. if k = 3 that mean print last 3 elements..

// source book

#include<iostream>
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
	cppNode* kthToLast(int k) {
		cppNode *p1 = this;
		cppNode *p2 = this;
		for(int i = 0; i < k -1; ++i) {
			p2 = p2->next;
		}

		while(p2->next != NULL) {
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
	bool printkToEnd(cppNode* p1) {
		while(p1->next != NULL) {
			cout <<  "k to End = " << p1->data << endl;
			p1 = p1->next;
		}
                cout <<  "k to End = " << p1->data << endl;

	}		
};

int main() {
        int data;
        cin >> data;
        cppNode node(data);

        for(int i = 0; i < 4; ++i) {
                cin >> data;
                node.insert(data);
        }
        node.print();
	int k; cout << "Enter the kth to End position" ; cin >> k; cout << endl;
	cppNode *p1 = node.kthToLast(k);
	node.printkToEnd(p1);

}

