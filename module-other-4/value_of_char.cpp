#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char* c = "helo";
	int value = 0, len = strlen(c);
	while(len >=0) {
		value += c[len-1];
		--len;
	}

	cout << "ASCII value of given string =" << value << endl ;
}
