// Reverse String: Implement a function void reversetchar* str) in C or C++ which reverses a null­ terminated string.

//reversing a string , take care of null char

// source book

#include<iostream>
using namespace std;

void StringRevers(char* str) {
	char* end = str; int counter=0;
	while(*end) { 
		++end; 
		counter++; }

	--end;
	char tmp; int midpoint = counter/2;
	while(midpoint >= 0 ) {
		tmp = *str;
		*str = *end;
		*end = tmp;
		--end; ++str;
		--midpoint;
	}


}

int main() {
	char s[] = "srinivas";
	StringRevers(s);
	cout << s << endl;
}
