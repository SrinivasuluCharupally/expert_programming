// source http://www.dcs.uni-pannon.hu/smidla/web/cplusplus/reference/algorithm/fill_n/index.html

#include<iostream>
#include<vector>
#include<algorithm> // this required for vector, not for array

using namespace std;

int main() {
	vector<int> v (8, 10);
	fill_n(v.begin(), 3, 5); // it shoudl e v.begin() because it's vector
	for(vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
		cout << *itr << endl;
}
