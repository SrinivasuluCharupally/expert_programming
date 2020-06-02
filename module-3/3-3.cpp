// this problem completly implemented using regular datastructure, no vectors at all
// for stack vector, refer 3-3-1.cpp, http://waxworksmath.com/Authors/G_M/Laakmann/Code/c_3_p_3.cpp
#include<iostream>
using namespace std;

class stack {
	int data;
	stack* next = NULL;
	stack* top = NULL;
	stack* plat = NULL;
	stack* platTop = NULL;
	stack* platTopNext = NULL;
	int max_count_in_stack;
	int local_counter;
  public:
	stack(int n) { max_count_in_stack = n; local_counter = n;  }
	stack() {}
	//~stack() { }

	void push(int d) {
		stack* plat;
		if(max_count_in_stack ==  local_counter) {
			plat = findPlat();
		}
		
		++local_counter;

		stack* newNode = new stack;
		newNode->data = d;
		if(plat->platTop == NULL) {
			plat->platTop = newNode;
		}
		else {
			newNode->next = plat->platTop;
			plat->platTop = newNode;
		}
//		plat->platTop = top;

	}
	
	stack* findPlat() {
                //if(max_count_in_stack ==  local_counter) {
                        stack* newplat = new stack;
                        if(plat == NULL) {
                                plat = newplat;
				local_counter = 0;
				return plat;
                        }
                        newplat->platTopNext = plat;
                        plat = newplat;
                        local_counter = 0;
			return plat;
                //}
		
	}

	void print() {
		cout << "Enter Print ...." << endl;
		stack* plattmp = plat;
		while(plattmp->platTopNext != NULL) {
			cout << "starting a plat" << plattmp->platTop << endl;
			stack* tmp = plattmp->platTop;
			while(tmp->next != NULL) {
				cout << "output = " << tmp->data << endl;
				tmp = tmp->next;
			}
                        cout << "output = " << tmp->data << endl;
			plattmp = plattmp->platTopNext;
		}
                        cout << "starting a plat" << plattmp->platTop << endl;
                        stack* tmp = plattmp->platTop;
                        while(tmp->next != NULL) {
                                cout << "output = " << tmp->data << endl;
                                tmp = tmp->next;
                        }
                        cout << "output = " << tmp->data << endl;

		return;
	}

	int pop() {
//		stack* tmp = top;
		cout << "poping one element " << top->data << endl;
		top = top->next;
	}
	

};


int main() {
	int data;
	int noOfElements;
	cout << "No of elements you have = " ;
	cin >> noOfElements;
	stack stackObj(4);
	for(int i = 0; i < noOfElements; ++i) {
		cin >> data;
		stackObj.push(data);
	}
	stackObj.print();
}
