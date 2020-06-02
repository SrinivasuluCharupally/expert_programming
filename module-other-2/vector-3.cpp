#include<iostream>
#include<vector>
using namespace std;

int main() {
vector<int> vec;
vec.push_back(10);
cout << vec[0] << endl;
cout << "size of = " << vec.size() << endl;
cout << "vec.at(0) " << vec.at(0) << endl;
vector<int> v(1);
v[0] = 20;
cout << v[0] << endl;
}
