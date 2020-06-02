#include <iostream>
using namespace std;


void fun(char c) {
if(c <= 'z') {
	cout << c << " ";
	fun(c+1);
	}
else
	cout << "heo";
}


int main() {
fun('A');
}
