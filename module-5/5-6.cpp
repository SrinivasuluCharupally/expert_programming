//Conversion: Write a function to determine the number of bits you would need to flip to convert integer A to integer B.

// ^ is XOR operation , The binary XOR operation (also known as the binary XOR function) will always produce a 1 output if either of its inputs is 1 and will produce a 0 output if both of its inputs are 0 or 1.



#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
int n = 10, m = 15, r = n^m, count = 0, bits=0;
while(r !=0 ) {
    bits += 1;
    r = r & (r-1);
}
    cout << " No of bits to flip are =" << bits << endl;
	return 0;
}


