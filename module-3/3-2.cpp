// Stack Min: How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop and min should all operate in 0(1) time.



#include<iostream>
using namespace std;
class node { 
    int data;
    stack* next = NULL;
};
class stack {
	stack* top = NULL;
	int min;
  public:
	stack() { }
	void push(int d) {
		stack* newNode = new node;
		newNode->data = d;
		if(top == NULL) {
			top = newNode;
			min = d;
			return;
		}
         else{
		min = d > min ? min : d;
	//	stack* tmp = top;
		newNode->next = top;
		top = newNode;
	}
      }
	
	void print() {
		stack* tmp = top;
		while(tmp->next != NULL) {
			cout << "output = " << tmp->data << endl;
			tmp = tmp->next;
		}
		return;
	}

	int pop() {
//		stack* tmp = top;

           If(top ==NULL) { cout << "stack is empty"; return;}

		cout << "poping one element " << top->data << endl;
		top = top->next;
	}
	
	int minFun() {
		return min;
	}

};

int main() {
	int data;
	stack stackObj;
	for(int i = 0; i < 4; ++i) {
		cout << " Enter one element = " ;
		cin >> data;
		stackObj.push(data);
	}
	stackObj.pop();
	cout << "Min value in stack" << stackObj.minFun() << endl;
	stackObj.print();
}
