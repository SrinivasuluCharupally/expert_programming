// building hash table

#include<iostream>
using namespace std;

class Hash {
	int key;
	int value;
 public:
	Hash* next = NULL;
	void set_values(int k, int v) {
		key = k; value = v;
	}
	void get_values() {
		cout << "key = " << key << " value = " << value << endl;
	}
	
};

class HashMap {
	Hash** table;
	//table = new Hash*[5];
  public:
	HashMap() {
	        table = new Hash*[5];
		for(int i = 0; i < 5; ++i) 
			table[i] = NULL;
	}

	void Insert(int key, int value) {
		int hashkey_ = key % 5;
		if(table[hashkey_] == NULL) {
			Hash* NewNode = new Hash;
			NewNode->set_values(key,value);
			table[hashkey_] = NewNode;
		}
		else {
			Hash* tmp = table[hashkey_];
			while(tmp->next != NULL)
				tmp = tmp->next;
			Hash* NewNode = new Hash;
			NewNode->set_values(key,value);
			tmp->next = NewNode;
		}
	}
	void Display(int key) {
		Hash* tmp = table[key%5];
		while(tmp->next != NULL) {
			tmp->get_values();
			tmp = tmp->next;
		}
                tmp->get_values();
	}
			
};

int main() {
	HashMap obj;
	obj.Insert(3, 120);
	obj.Insert(2, 210);
	obj.Insert(2,330);
	obj.Display(2);
}
	
