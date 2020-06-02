// qsort will not work for string as the qsort was defined in c style, c does not support strings

// for c++, use sort

// source https://stackoverflow.com/questions/18292619/c-string-array-sorting

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
  string name[] = {"john", "bobby", "dear", 
                   "test1", "catherine", "nomi", 
                   "shinta", "martin", "abe", 
                   "may", "zeno", "zack", "angeal", "gabby"};

  int size = sizeof(name)/sizeof(name[0]);
  sort(name, name+size);
  for(int i = 0; i < size; ++i)
	cout << name[i] << endl;

}
