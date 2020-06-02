#include <iostream>
#include "example_struct.h"
#include <cassert>
#include <string>
#include <fstream>
using namespace std;

int main() {
CS_t intStash, stringStash;
int i;
char* cp;
ifstream in;
string line;
const int bufsize = 80;
initialize(&intStash, sizeof(int));
for(i=0; i < 100; i++) add(&intStash, &i);
for(i=0; i < count(&intStash); i++)
	cout << "fetch(&intStash, " << i << ") = "
	     << *(int*)fetch(&intStash, i)
	     << endl;
initialize(&stringStash, sizeof(char)*bufsize);
in.open("example_struct.cpp");
assert(in);
while(getline(in, line))
	add(&stringStash, line.c_str());
i = 0;
while((cp = (char*)fetch(&stringStash, i++))!=0)
	cout << "fetch(&stringStash, " << i << ") = "
	     << cp << endl;
cleanup(&intStash);
cleanup(&stringStash);
}

	
