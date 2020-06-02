// const is used for vairables

// constexpr is used for functions return type saying that perticular function return a const value... so compiler can validate it at compile time instead at runtime...

// source https://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const


#include<iostream>
using namespace std;

constexpr int func(int i , int j) {   // it's clear that 4, 5 are fixed and you get return value a const all the time so making it as constexptr tells to compiler that compiler can optimize it and find at compile time

	return i*j;
}

int main() {
	const int i = 10; // it says to compiler that the value of i is fixed...

	const int value = func(4,5); // constexpr return time

}

