// use of different random() number generator

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main() {
 srand(time(NULL));
  int iSecret = rand() % 10 + 1;

	int rand1 = rand()%10;

	cout << "rand() = " << rand1 << endl;
}

