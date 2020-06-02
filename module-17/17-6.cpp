//  Count of 2s: Write a method to count the number of 2s between O and n.

// source book

// simple one : https://www.google.co.in/amp/s/www.geeksforgeeks.org/number-of-occurrences-of-2-as-a-digit-in-numbers-from-0-to-n/amp/

#include<iostream>
using namespace std;
/*
int NoOf2s(int n) {
        int count = 0, multiply = 1, itr = 0;;
	int p = 0;
	while(n>0) {

		int tmp = n %10;
		if(tmp >2 ) {
			count = count + multiply ; // for 20, 21, 23, ....
		}
		if(tmp == 1) { } 
                count = count + tmp*itr ; // for 2, 12, 32, 42, ....

                n /= 10;
		multiply *= 9;
		++itr;


	int powerof10 = 10^d;
	int nextpowerof10 = powerof*10;
	int right = number % powerof10;
	int rounddown = number - number % nextpowerof10;
	int roundup = rounddown + nextpowerof10;
	int digit = (number / powerof10) %10;

	if ( digit < 2) return rounddown/10;
	else if(digit == 2) return rounddown / 10 +right +1;
		else return roundup/10;
	}

	return count;
}
*/

int count2s(int number, int itr) {
        int powerof10 = 10^itr;
        int nextpowerof10 = powerof10*10;
        int right = number % powerof10;
        int rounddown = number - number % nextpowerof10;
        int roundup = rounddown + nextpowerof10;
        int digit = (number / powerof10) %10;

        if ( digit < 2) return rounddown/10;
        else if(digit == 2) return (rounddown / 10 +right +1);
                else return roundup/10;
}

void Final2scount(int number) {
	int tmp = number;
	int total = 0, itr = 0;
	while(tmp > 0) {
		total += count2s(number, itr);
		++itr;
		tmp /= 10;
	}
	cout << " Tota = " << total << endl;
}

int main() {
	int in;
	cout << "Enter number = " ; cin >> in;
	Final2scount(in);
	//cout << "No of 2 is = " << count << endl;
}
