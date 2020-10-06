// Next Number: Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation

#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
int n =5, getbit = 0, count = 0;

while(n != 0) {
    if(n & (1 << getbit)) {
        count += 1;
    }
    n = n & (~(1 << getbit));
    getbit += 1;
}
cout << "no of 1's = " << count << endl;

int small = (1 << count) -1;
cout << " smallest number haveing same 1's = " << small << endl;
int big = (-1 << (getbit - count)) & ((1 << getbit)-1) ;
// simple way could be "small << (getbits - count)" 
int x =  ((1 << (getbit+1))-1);
cout << " biggets number having same 1's = " << big << endl;
	return 0;
}

