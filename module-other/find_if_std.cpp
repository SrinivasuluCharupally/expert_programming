/// @brief: finding a avlue in the given range.

/// @brief: source : http://www.cplusplus.com/reference/algorithm/find_if/

#include<iostream>
#include<vector>
#include<algorithm> // find_if was declared here
using namespace std;

bool isodd(int i) {
	return (i%2 ==1);
}


int main() {
	vector<int> myvector = {10, 25, 30, 35};
	vector<int>::iterator itr = find_if(myvector.begin(), myvector.end(), isodd);
	cout << "Find odd value = " << *itr << endl;
}
