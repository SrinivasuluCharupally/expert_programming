// measuring clock using clcok

#include<iostream>
using namespace std;

int main() {
	clock_t begin = clock();
	cout << "helo" << endl;
	clock_t end = clock();
	double elapsed = (double)(end-begin)/CLOCKS_PER_SEC;

	cout << "Time = " << elapsed;
}
