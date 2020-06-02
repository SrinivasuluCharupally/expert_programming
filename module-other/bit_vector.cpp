//A bit array (also known as bitmap, bitset, bit string, or bit vector) is an array data structure that compactly stores bits. It can be used to implement a simple set data structure. A bit array is effective at exploiting bit-level parallelism in hardware to perform operations quickly.

// bit vector is similar to vector<bool>

// source https://github.com/nickzuber/BitVector


#include<iostream>
#include<vector>
using namespace std;

int main() {
	bit_vector bv[5];
	bv.push_back(true);
        bv.push_back(true);
        bv.push_back(false);
        bv.push_back(true);
        bv.push_back(true);

}
