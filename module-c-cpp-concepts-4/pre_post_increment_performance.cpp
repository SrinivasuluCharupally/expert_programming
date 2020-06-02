//measuring performance of ++i & i++

#include<iostream>
#include<ctime>
using namespace std;

int main() {
	double i =0;
	clock_t begin = clock();	
	for(i; i < 10000000000; ++i) {
		i = i;
	}
	clock_t end = clock();
	double elapsed = double(end-begin)/CLOCKS_PER_SEC;

	cout << "Time ++i = " << elapsed << endl;

	 begin = clock();
	for(double i =0; i < 10000000000; i++) {
		i = i;
	}
	 end = clock();
	 elapsed = double(end-begin)/CLOCKS_PER_SEC;
	cout << "Time i++ = " << elapsed << endl;
}


