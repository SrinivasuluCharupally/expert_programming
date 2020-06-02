#include<iostream>
#include<vector>
using namespace std;

int main() {
vector<int> v;
v.push_back(10);
v.push_back(20);
for(vector<int>::iterator i  = v.begin(); i != v.end(); ++i) {
 cout << *i << endl;
}
cout << v.size() << endl;
for(int i = 0; i != v.size(); i++ ) {
cout << v[i] << endl;
}
}
