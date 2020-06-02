// printing all combinations of given no.of binary digits

#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int digits = 3;
	int totalCombinations = pow(2,digits);
	for(int i = 0; i < totalCombinations; ++i) {
		for(int j = 0; j<digits; ++j) {
			if(i & (1<<j)) cout  << 1;
			else cout << 0;	
		}
		cout << endl;
	}
}
