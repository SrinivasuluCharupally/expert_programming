#include<iostream>
using namespace std;

int fun(int a, int b = 3) {
	return a+b;
}

int main() {
	cout << "fun(4) " << fun(4) << endl;
	cout << "fun(4,5) " << fun(4, 5) << endl;
}
