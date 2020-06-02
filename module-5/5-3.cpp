// Flip Bit to Win: You have an integer and you can flip exactly one bit from a O to a 1. Write code to  nd the length of the longest sequence of 1 s you could create 


#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
int n = 10;
int getbit = 0, currentlength = 1, previouslength = 0;
bool tracker;
while(n != 0) {
    if(n & 1<<getbit) { currentlength += 1; }
    else { previouslength = currentlength-1; currentlength =1; }
    n = n & (~(1 << getbit));
    getbit += 1;
}
cout << " no of contiouse 1's = " << current + previous << endl;
	return 0;
}
