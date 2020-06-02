// Add Without Plus: Write a function that adds two numbers. You should not use+ or any arithmetic operators


// source book

#include<iostream>
using namespace std;

int Addition(int one, int second) {
/*
	int max = one > second ? one : second;
	int min = one < second ? one : second;
	string s;
	for(int i = 0; max >0; max/2, ++i) {
		int k = max%2; max /= 2;
		int l = min%2; min /= 2;
		int resOR = k ^ l; int resAND = k & l;
	}
*/

	int resOR = one ^ second;
	int resAND = one & second;
	resAND = resAND<<1;
	int result = resOR | resAND;
	return result;
}

int main() {
	int one, second;
	cout << "Enter one = " ; cin >> one;
	cout << "Enter second = " ; cin >> second;

	int result = Addition(one, second);
	cout << "Result = " << result << endl; 
}
