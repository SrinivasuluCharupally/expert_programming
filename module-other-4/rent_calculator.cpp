#include <iostream>
#include<stdlib.h>
using namespace std;

int main(int argc, char* argv[]) {
	// your code goes here
	int rent = 210000;
	int totalrent = 0;
	int years = 40;
	
	for(int i = 0; i < years; ++i) {
	       totalrent = totalrent + rent*12;
		float f = atof(argv[1]);	
	       rent = (rent + (rent*f));
	       cout << " " << atof(argv[1]) ;
	       cout << " Monthly rent = " << rent << endl;
	}
	cout << " Final  rent = " << totalrent << endl;
	return 0;
}
