//PairwiseSwap: Writeaprogramtoswapoddandevenbitsinanintegerwithasfewinstructionsas possible (e.g., bit O and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).


#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
int x=10;
   int result = ( ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
   cout << "integer after bits swapped = " << result << endl;
	return 0;
}
