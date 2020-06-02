#include<iostream>
using namespace std;

class Node {
  public:
	int data ;
	Node* next;
  public:
	Node(int d) : data(d) { next = NULL;}
};

class BuildList {
	Node* n;
	Node* head;
  public:
   	BuildList() { head = NULL; }
	void insert(int d) {
		n = new Node(d);
		if(head == NULL)  { head = n; return; }
		Node* current = head;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = n;
	}

	void display() {
		Node* tmp = head;
		while(tmp != NULL) {
			cout << " " << tmp->data << endl;
			tmp = tmp->next;
		}
		return;
	}
};

int main() {
	BuildList b;
	b.insert(20);
	b.insert(30);
	b.insert(400);
	b.display();
	
}
