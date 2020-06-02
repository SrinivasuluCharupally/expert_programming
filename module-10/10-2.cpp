// Group Anagrams: Write a method to sort an array ot strings so that all tne anagrnms are next to each other.
// { "cat”, “dog”, “tac”, “god”, “act”}, then output may be {"cat" "tac"  "act" "dog" "god”.}


// sorce http://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/


#include<iostream>
#include<string.h>
using namespace std;

class Hash{
public:
	char* str;
	int key;
	Hash* next = NULL;
};

class HashMap {
	Hash** table;
  public:
	HashMap(int total_strs) {
		table = new Hash*[total_strs];
		for(int i = 0; i < total_strs; ++i)
			table[i] = NULL;
	}

	void insert(char* str, int total_strs );
	void display();
};

void HashMap::insert(char* str, int total_strs) {
	
	int str_len =  strlen(str);
	int value = 0; 
	while(str_len >= 0) {	value += str[str_len]; --str_len; }
      
	int hash_key = value % total_strs;
	if(table[hash_key] == NULL) {
		Hash* new_node = new Hash;
		new_node->key = value;
		new_node->str = str;
		table[hash_key] = new_node;
		return;
	}
          if(compare(table[hash_key]->str, str)) { 
       	Hash* new_node = new Hash;
       	new_node->key = value;
       	new_node->str = str;
	Hash* tmp = table[hash_key];
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = new_node;
   }
}

void HashMap::display() {
 for(int i = 0; i < 5; ++i) {
        Hash* tmp = table[i];
	if(tmp == NULL) continue;
        while(tmp->next != NULL) {
		cout << "key = " << tmp->key << " value = " << tmp->str;
                tmp = tmp->next;
        }
        cout << "key = " << tmp->key << " value = " << tmp->str;
	cout << endl;
}
}


void printAnagramsTogether(char* str[], int total_strs) {
	HashMap map(total_strs);
	for(int i = 0; i < total_strs; ++i) 
		map.insert(str[i], total_strs);

	map.display();
}

int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act"};
 //   int size = sizeof(wordArr) / sizeof(wordArr[0]);
    sort(wordArr); // first sort each word
    printAnagramsTogether(wordArr, 5);
    return 0;
}
