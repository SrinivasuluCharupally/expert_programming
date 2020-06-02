
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string,bool> mymap = {{"hi",true}, {"be",true}};
	string s = "hi";
	map<string,bool>::iterator itr = mymap.find(s);
	if(itr != mymap.end())
		cout << "found" <<itr->first <<  endl;
}
