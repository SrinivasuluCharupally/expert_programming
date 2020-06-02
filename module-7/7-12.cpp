// Hash table implementation using List
// this implementation does not really stores "key" 

#include<iostream>
#include<list>
using namespace std;

#define TABLE_SIZE_ 10

class Hash {
	list<int>* table;
	int key_;
  public:
	Hash() {
		table = new list<int>[TABLE_SIZE_];
	}
	void insert(int key, int value) {
		table[key].push_back(value);
	
	}

	void insert(int value) {
		int key = value % TABLE_SIZE_;
		table[key].push_back(value);
	}
	int displayTable(int key) {
		for(list<int>::iterator itr = table[key].begin(); itr != table[key].end(); ++itr) {
			cout << " key = " << key << " element = " << *itr << endl;
		}
	}
};

int main() {
	Hash hashTable;
	hashTable.insert(0,10);
	hashTable.insert(1, 11);
        hashTable.insert(1, 21);
        hashTable.insert(31);
	hashTable.displayTable(1);

}
