// Rand7 from Rand5: Implement a method rand7 () given randS (). That is, given a method that generates a random number between O and 4 (inclusive), write a method that generates a random number between O and 6 (inclusive)


#include<iostream>
#include<stdlib.h>
using namespace  std;

int r5() {
	return rand()%5;
}

int main() {
	int x = rand(); // it's function of stdlib.h
	int result;
	while(true) {
	int rand1 = r5();
	int rand2 =  r5()%2;
	result= rand1 + rand2;
		if(result <7) break;
	}
	cout << "rand7() from rand5() = " << result  << endl;
}
