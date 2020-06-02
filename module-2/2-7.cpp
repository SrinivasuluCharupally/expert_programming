// Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.


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
	static bool isIntersectable(cppNode* node1, cppNode* node2) {
		cppNode* tail1 = node1->findTail();
		cppNode* tail2 = node2->findTail();
		int length1 = node1->findLength();
		int length2 = node2->findLength();
		if(tail1->data != tail2->data) {
			return false;
		}
		return true;
	}
	int findLength() {
		cppNode* tmp = this;
		int length = 0;
		while(tmp->next != NULL) {
			++length;
			tmp = tmp->next;
		}
		return ++length;
	}
	cppNode* findTail() {
		cppNode* tail = this;
		while(tail->next != NULL) {
			tail = tail->next;
		}
		return tail;
	}
	static cppNode* findIntersectingNode(cppNode* node1, cppNode* node2) {
                cppNode* tail1 = node1->findTail();
                cppNode* tail2 = node2->findTail();
                int length1 = node1->findLength();
                int length2 = node2->findLength();
		cppNode* longerNode = length1 > length2 ? node1 : node2;
		cppNode* shorterNode = length1 < length2 ? node1 : node2;
		int position = length1 > length2 ? (length1 - length2) : (length2 - length1);
		while(position > 0) {
			longerNode = longerNode->next;
			--position;
		}
		while(longerNode->data != shorterNode->data) {
			longerNode = longerNode->next;
			shorterNode = shorterNode->next;
		}
		return longerNode;
	}
	void intersect() {
		cppNode* tmp = this;
        cout << "Intersecting Node is " << tmp << " Data = " << tmp->data << endl;
	}

};

int main() {
	int data1, data2;
        cout << "Enter First list...." << endl;
	cin >> data1;
	cppNode node1(data1);
	for(int i = 0; i < 6; ++i) {
		cin >> data1;
		node1.insert(data1);
	}
	node1.print();

        cout << "Enter Seconid list...." << endl;
	cin >> data2;
        cppNode node2(data2);
        for(int i = 0; i < 4; ++i) {
                cin >> data2;
                node2.insert(data2);
        }
        node2.print();

	if(!cppNode::isIntersectable(&node1, &node2)) {
		cout << "Not intersectable" << endl;
		return 0;
	}
	cout << "Both the lists are Insersectable ... Good" << endl;
	
	cppNode* intersetNode = cppNode::findIntersectingNode(&node1, &node2);
	intersetNode->intersect();
}

