// Sparse Search: Given a sorted array of strings that is interspersed with empty strings, write a method to  nd the location of a given string


#include<iostream>
#include<string.h>
using namespace std;

int BinarySearch(string* str, int low, int high, string find_element) {

//	if(str == find_element) return 
	int mid = (low+high)/2;

        while(str[mid].empty()) {
              mid--;
        }

	if(str[mid] == find_element) return mid;


	if(str[mid].at(0) > find_element.at(0) && !str[mid].empty() ) {
		return BinarySearch(str, low, mid, find_element);
	}
	else {
		return BinarySearch(str,  mid+1, high,  find_element);
	}
	
	return -1;


}

int main() {

	string str[8] = {"ball", "", "dell", "helo", "", "", "new", ""};
	string find_element = "new";
	int element_index = BinarySearch(str, 0, 8, find_element);
	cout << "index of " << " find_element " << element_index << endl;
	return 0;
}
