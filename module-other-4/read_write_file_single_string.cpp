#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
ifstream in ("cpp1.cpp");
ofstream out("tmp1.txt");
string s, line;
while(getline(in, line)) 
	s += line + "\n";
out <<s<<endl;
}
	
