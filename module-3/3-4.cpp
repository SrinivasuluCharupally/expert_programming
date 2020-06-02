//Implement a Queue data structure using two stacks. 
//source http://www.csegeek.com/csegeek/view/tutorials/algorithms/stacks_queues/stk_que_part3.php


#include<iostream>
#include<stack>
using namespace std;

class queue {
	stack<int> s1, s2;
  public:
	void enqueue(int d);
	void dequeue();
	void  print();
};

void queue::enqueue(int d) {
	s1.push(d);
}

void queue::dequeue() {
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
//	int dequeueval = s2.top
	cout << "Dequeueing element = " << s2.top() << endl;
	s2.pop();
	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
}

int main() {
	class queue queueObj;
	int data;
	for(int i =0; i < 5; ++i) {
		cin >> data;
		queueObj.enqueue(data);
	}
	queueObj.dequeue();
}
