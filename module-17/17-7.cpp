// Baby Names: Each year, the government releases a list of the 10,000 most common baby names and their frequencies (the number of babies with that name). The only problem with this is that some names have multiple spellings. For example, "John" and ' jon' are essentially the same name but would be listed separately in the list. Given two lists, one of names/frequencies and the other of pairs of equivalent names, write an algorithm to print a new list of the true frequency of each name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and Johnny are synonyms. (It is both transitive and symmetric.) In the  final list, any name can be used as the "real" name


// source own = use multi map to create a graph, then pull all values for one key then use tracker to make sure dont traverse again, then find total

#include<iostream>
#include<map>
using namespace std;

int main() {
	multimap<string, string> mymap = { {"hi", "h"}, {"hi", "i"}, {"bye", "b"}, {"hi", "hh" }};


	pair<multimap<string,string>::iterator, multimap<string,string>::iterator > res = mymap.equal_range("hi");

	for(multimap<string,string>::iterator itr = res.first; itr != res.second; ++itr) 
		cout << itr->second;

}

