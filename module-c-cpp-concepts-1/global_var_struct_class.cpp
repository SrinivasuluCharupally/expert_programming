#include<iostream>
using namespace std;

int count =0;

struct Node {
	int x;
}Node;

void inc() {
	++count;
	cout << " inc " << count << endl;
}

class classNode {
	int c;
 public:
	classNode() {}
	void classinc() {
		count = 10;
	        cout << " inc " << count << endl;

	}
};


int main() {
	classNode obj;
	obj.classinc();
	inc();
}

