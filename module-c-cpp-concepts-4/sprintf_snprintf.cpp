// this is to find difference b/w sprintf() and snprintf()

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main() {
	const char* p = new char;
	string s = "helo world" ;
	p = s.c_str();
	cout << p << endl;
	char buff[20];
	sprintf(buff, "%s", p);
	cout << buff << endl;
	snprintf(buff, 5, "%s", p);
	cout << buff << endl;
}
