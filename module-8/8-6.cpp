// Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different  sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following constraints:(1) Only one disk can be moved at a time.(2) A disk is slid off the top of one tower onto another tower.(3) A disk cannot be placed on top of a smaller disk

//source book


#include<iostream>
#include<stack>

using namespace std;

class Tower{
	stack<int> disksStack_;
	int towerIndex_; 

  public:
//	Tower() {}
	Tower(int index) {
		//disksStack_ = new stack<int>;
		towerIndex_ = index;
	}

	void addDisk(int disk) {
		if(!disksStack_.empty()) {
			if(disksStack_.top() < disk) {
				cout << " Will not add the disk" << endl;
			}
	                else disksStack_.push(disk);
		}
		else disksStack_.push(disk);
	}
	void moveTopTo(Tower* tower) {
		int disk = disksStack_.top();
		disksStack_.pop();
		tower->addDisk(disk);
	}
	
	void InterChanging(int n, Tower* destination, Tower* buffer) {
		if(n > 0) {
			InterChanging(n-1,buffer, destination); 
			moveTopTo(destination);
			buffer->InterChanging(n-1, destination, this);	
		}
	}
	void print() {
		stack<int> tmp = disksStack_;
		while(!tmp.empty()) {
			cout << tmp.top() << endl;
			tmp.pop();
		}
		
	}
};


int main() {
	Tower* t0 = new Tower(0);
        Tower* t1 = new Tower(1);
        Tower* t2 = new Tower(2);

	for (int i = 4; i > 0; --i) {
		t0->addDisk(i);
	}
        cout << "initial tower" << endl;
        t0->print();

	t0->InterChanging(4, t2, t1);
	cout << "after changed" << endl;
	t2->print();
	t1->print();
}
	

