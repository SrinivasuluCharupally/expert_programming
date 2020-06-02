// Hash Table vs STL Map: Compare and contrast a hash table and an STL map. How is a hash table implemented? If the number of inputs is small, which data structure options can be used instead of a hash table?


// map STLimplentation 


// source http://www.cplusplus.com/reference/map/map/insert/


#include<iostream>
#include<map>
using namespace std;

int main() {
	map<char, int> mymap;
	mymap.insert(pair<char,int> ('a',10));

	pair<map<char,int>::iterator, bool> ret = mymap.insert(pair<char,int>('b',20));

	if(ret.second == false)
		cout << "element exit" << endl;
	else 	cout << "element does not exit" << endl;

	for(map<char,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
		cout << itr->first << itr->second << endl;
}
