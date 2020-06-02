// bit set 
// source http://www.cplusplus.com/reference/bitset/bitset/set/

#include<iostream>
#include<bitset>
using namespace std;

int main() {
	bitset<10> bs;
	bs.set(3,1);
	bs.set(5,1);
	cout << bs << endl;
	cout << bs.test(4) << endl;
	cout << bs.test(5) << endl;
}

