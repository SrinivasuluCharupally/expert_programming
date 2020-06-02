// Three in One: Describe how you could use a single array to implement three stacks.

//implement a array using 3 stacks
// this algo works for n stacks to , k = no.of stack in mina()

// source http://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/


#include<iostream>
using namespace std;

class kStacks {
	int* arr;
	int* top;
	int* next;
	int n, k;
	int free;

  public:
	kStacks(int k, int n);
	bool isFull() { 
		return (free == -1);
	}

	void push(int item, int sn);
	int pop(int sn);
	bool isEmpty(int sn) {
		return (top[sn] == -1);
	}
};

kStacks::kStacks(int k1, int n1) {
	n = n1; //10
	k = k1; //3
	arr = new int[n];
	top = new int[k];
	next = new int[n];
	for(int i = 0; i < k; ++i) {
		top[k] = -1;
	}

	free = 0;
	for(int i = 0; i < n-1; ++i) {
		next[i] = i+1;
	}
	next[n-1] = -1;
}

void kStacks::push(int item, int sn) {
	if(isFull()) {
		cout << "Stack Overflow" << endl;
		return;
	}
		
	int i = free;
	free = next[i];
	next[i] = top[sn];
	top[sn] = i;
	arr[i] = item;
}

int kStacks::pop(int sn) {
	if(isEmpty(sn)) {
		cout << "Stack underflow" << endl;
		return -1;
	}
	int i = top[sn];
	top[sn] = next[i];
	next[i] = free;
	free = i;
	return arr[i];
}

int main() {
	int k = 3, n = 10;
	kStacks ks(k, n);
    ks.push(15, 2);
//    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
     ks.push(45, 2);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	ks.push(41, 0);
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;

 
    return 0;
}
	


