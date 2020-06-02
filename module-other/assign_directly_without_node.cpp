#include<iostream>
using namespace std;

class Node {
	int data;
	Node* next;
  public:
	void insert(int d) {
		Node* k = new Node;
		k->data = d;
		Node* tmp = k->next;
		tmp = new Node;
		tmp->data = 20;
		cout << k->next << endl;
	}
};

int main() {
	Node n;
	n.insert(20);
}

