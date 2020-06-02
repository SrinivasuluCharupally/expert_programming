// unordered_map and map difference ...
// unordered = no order, it stores the same way you push
// map = it's sorted version of given pairs


#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;

int main() {

	map<int, int> mymap;
	unordered_map<int,int> myunorderedmap;
	
	mymap.insert(pair<int,int>(10, 2));
        mymap.insert(pair<int,int>(5, 2));
        mymap.insert(pair<int,int>(15, 2));

        myunorderedmap.insert(pair<int,int>(10, 2));
        myunorderedmap.insert(pair<int,int>(5, 2));
        myunorderedmap.insert(pair<int,int>(15, 2));

	for(auto &x : mymap)
		cout << "map " << x.first << " " << x.second << endl;

	for(auto& x : myunorderedmap)
		cout << "unodered " << x.first << " " << x.second << endl;
}


