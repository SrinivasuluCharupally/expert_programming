
#include<iostream>
using namespace std;

void fun(char c[]) {
	c[2] ='d';
};

int main() {
	char c[] = "helo";
	fun(c);
	cout << c << endl;
	char* s = "helo"; // not allowed, should be constat
	fun(s);
	cout << s << endl;
	char* s1 = new char[4]; // all ways "new" requires for pointer
}
