// Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and is Empty.


#include<iostream>
#include<stack>
using namespace std;
class cppstack {
	stack<int> s1;
  public:
	void push(int d) {
		s1.push(d);
	}

	void sort() {
		}
	void print() {
		stack<int> tmp = s1;
		while(!tmp.empty()) {
			cout << "element = " << tmp.top() << endl;
			tmp.pop();
		}
	}
	void mysort() {
		stack<int> s2;
		while(!s1.empty()) {
			int buffer = s1.top();
			s1.pop();
			while(!s2.empty() && s2.top() > buffer) {
				s1.push(s2.top());
				s2.pop();
			}
			s2.push(buffer);
		}
		while(!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}
};

int main() {
	cout << "Enter stack elements... 5" << endl;
	int data;
	cppstack stackObj;
	for(int i = 0; i < 5; ++i) {
		cin >> data;
		stackObj.push(data);
	}
	stackObj.print();
	stackObj.mysort();
        cout << " After softed...." << endl;
	stackObj.print();

}

		
