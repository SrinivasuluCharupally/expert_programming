// brut force algorithm

#include<iostream>
using namespace std;

int TripleStep(int);

int main() {
	int n = 3;
	int result =  TripleStep(n);
	cout << "No of combinations of TripleStep = " << result << endl;
}

int TripleStep(int n) {
	if(n < 0) return 0;
	if(n == 0) return 1;
	return TripleStep(n-1) + TripleStep(n-2) + TripleStep(n-3);
}
