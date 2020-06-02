// finding dublicat numbers in 32000 numbers using 4KB.

// use bitset http://www.cplusplus.com/reference/bitset/bitset/bitset/http://www.cplusplus.com/reference/bitset/bitset/bitset/

// source book using bitset

#include<iostream>
#include<bitset>

using namespace std;

int main() {
	int arr[9] = {1, 2,3,4,1,6,7,8,10};

	bitset<9> bs;
	cout << bs << endl;
	int i;
	for(i = 0; i < 9; ++i) {
		if(bs.test(arr[i])) {
			break;
		}
		bs.set(arr[i],1);

	}

	cout << "Dublicate number possition " << i << endl;
}

