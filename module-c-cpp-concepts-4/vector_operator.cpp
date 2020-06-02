#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() {

vector<string> v;
ifstream in("cpp1.cpp");
string word;
while(in >> word)
v.push_back(word);
for (int i=0; i<v.size(); i++)
cout << v[i] <<endl;
}
