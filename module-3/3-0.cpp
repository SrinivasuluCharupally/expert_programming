// Stack & Queue implementation ....


#include<iostream>
using namespace std;

class stack {
	int data;
	stack* next = NULL;
	stack* head = NULL;
  public:
	stack() {
	//	data = d;
	}

	bool push(int d) {
//		stack* head = this;
//                if(head == NULL) {
//			return false;
//		}
		stack* newNode = new stack;
		newNode->data = d;
		newNode->next = head;
		head = newNode;
		return true;
	}

	int pop() {
//		stack* head = this;
		int headData = head->data;
		head = head->next;
		return headData;
	}

	int peek() {
//		stack* head = this;
		return head->data;
	}

	bool isEmpty() {
//		stack* head = this;
		if(head == NULL) {
			return true; 
		}
		return false;
	}
	
	void print() {
		stack* headtmp = head;
		while(headtmp->next != NULL) {		
			cout << " out = " << headtmp->data << endl;
			headtmp = headtmp->next;
		}
                cout << " out = " << headtmp->data << endl;
	}
};

class queue {
	int data;
	queue* next = NULL;
	queue* head = NULL;

  public: 
	bool add(int d) {
		queue* newNode = new queue;
		newNode->data = d;
		queue* tmp = head; 
		if(head == NULL) { 
			head = newNode; 
			return true;
		}
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		return true;
	}
	void remove() {
//		queue* tmp = head;
		cout << "Removing from queue = " << head->data << endl;
		head = head->next;
	}
	
};
		

int main() {
	cout << "Starting Stack operations .... ";
	cout << "Enter stack value, upto 5 nodes" << endl;
	int data;
	stack stackObj;
	for(int i = 0; i < 5; ++i) {
		cin >> data;
		stackObj.push(data);
	}
	stackObj.print();
	int headData = stackObj.pop();
	cout << "Poping one node, value at the node " << headData << endl;
	int peekData = stackObj.peek();
	cout << "Peek node value = " << peekData << endl;
	cout << "Is empty stack = " << stackObj.isEmpty() << endl;


	cout << "Starting Queue operations ... " << endl;
	queue queueObj;
        for(int i = 0; i < 5; ++i) {
                cin >> data;
                queueObj.add(data);
        }
	queueObj.remove();

}
		
	
	

	
	
		
	
		
