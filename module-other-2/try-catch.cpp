#include<iostream>
#include<vector>
using namespace std;

int main() {
try {
	vector<int> vec(10);
	cout << vec.at(5) << vec.at(11) << endl;
} catch (std::exception& e) {
	cout << e.what() << endl;
	}

}

