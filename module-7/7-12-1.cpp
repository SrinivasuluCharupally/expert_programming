// hash table without using stl, like list, vector...
// avoid hash collisions , https://www.youtube.com/watch?v=h2d9b_nEzoA

// source http://www.sanfoundry.com/cpp-program-hash-tables-list-heads/
#include<iostream>
using namespace std;

#define SIZE 5

class HashEntry {
	int key_;
	int value_;
  public:
	HashEntry* next_;
  public:
	HashEntry(int key, int value) : key_(key), value_(value) { next_ = NULL;}
	int getvalue() { return value_;}
	int getkey() { return key_; }
};

class HashMap {
	HashEntry** table_;
	HashEntry* current;
  public:
	HashMap() {
		table_ = new HashEntry* [SIZE];
		for(int i = 0; i < SIZE; ++i ) {
			table_[i] = NULL;
		}
	}
	void insert (int key, int value) {
		int hash = key % SIZE;
//		HashEntry* current;
		if(table_[hash] == NULL) {
			table_[hash] = new HashEntry(key, value);
//			table_[hash]->next_ = 
		}
		else {
			current = table_[hash];
			while(current->next_ != NULL) {
				current = current->next_;
			}
			current->next_ = new HashEntry(key,value);
		}
	}
	void display(int key) {
		int hash = key % SIZE;
		HashEntry* current = table_[hash];
		while(current != NULL) {
			cout << " value at "<< hash << " is = " << current->getvalue() << " key = " << current->getkey() << endl;
			current = current->next_;
		}
	}
};


int main() {
	HashMap h;
	h.insert(2, 20);
	h.insert(3,30);
	h.insert(4,40);
	h.insert(6,10);
	h.insert(7,70);
	h.display(2);
}		
