// map STL
// source http://www.cplusplus.com/reference/map/map/insert/

#include<iostream>
#include<map>
using namespace std;

int main() {
	multimap<char, int> mymap;
	mymap.insert(pair<char,int> ('a',10));
        mymap.insert(pair<char,int> ('a',11));

//	pair<multimap<char,int>::iterator, bool> ret = mymap.insert(pair<char,int>('b',20));

//	if(ret.second == false)
//		cout << "element exit" << endl;
//	else 	cout << "element does not exit" << endl;

	pair<char, int> mypair;
	mypair = make_pair('C', 3);
	mymap.insert(mypair);
	int i = mymap.count('a');
	cout << "counter = " << i  << endl;

	for(multimap<char,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
		cout << itr->first << itr->second << endl;
}
