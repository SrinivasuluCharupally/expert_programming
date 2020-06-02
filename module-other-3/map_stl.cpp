// map STL
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
	pair<char,int> res = make_pair('b',20);

	mymap.insert(res);
	for(map<char,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr)
		cout << itr->first << itr->second << endl;

	map<char,int>::iterator itr = mymap.find('b');

	if(itr != mymap.end()) cout << "Founding.." << endl;
}
