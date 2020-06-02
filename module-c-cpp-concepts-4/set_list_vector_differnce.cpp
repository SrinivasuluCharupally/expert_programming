#include<iostream>
#include<list>
#include<set>
#include<vector>
using namespace std;

int main() {
	set<int> s;
	
	pair<set<int>::iterator,bool> res;
	res = s.insert(3);
	res = s.insert(3);
	res = s.insert(4);
	if(res.second) cout << " helo" << endl;
	else cout << "eixit" << endl;

	int x = s.find(3) != s.end();
	cout << "find 3 " << x << endl;

	for(set<int>::iterator itr = s.begin(); itr != s.end(); ++itr)
		cout << "set != " << *itr << endl; // set does not support itr < s.end()

	vector<int> v;
	v.push_back(2);
        for(vector<int>::iterator itr = v.begin(); itr < v.end(); ++itr)
                cout << "vector < " << *itr << endl;

        for(vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
                cout << "vector != " << *itr << endl;

	list<int> l;
	l.push_back(5);
//        for(list<int>::iterator itr = l.begin(); itr < l.end(); ++itr)
//                cout << " list < " << *itr << endl;

        for(list<int>::iterator itr = l.begin(); itr != l.end(); ++itr)
                cout << "list != " << *itr << endl; // list does not support itr < l.end()

}

