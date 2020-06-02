#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
ifstream in("cpp1.cpp");
ofstream out("tmp.txt");
string s;
while(getline(in,s))
	out << s << "\n";
}
