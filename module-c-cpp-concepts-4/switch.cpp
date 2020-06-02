#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main() {
char c;
bool quit;
  while(quit == false) {
	cout << " l - left ,r - right, q - quit " << endl;
	cin >> c;
	switch(c) {
		case 'l' : cout << " left selected " << endl; break;
		case 'r' : cout << " right selected " << endl; break;
		case 'q' : cout << "quting .. " << endl; quit = true;  break;
		default : cout << " select one";
	}
  }

int value = 2;
	cout << "executing second switch case ... " << endl;
	switch(value) {
		case 1: cout << "case1" << endl;
		case 2: cout << "case2" << endl;
		case 3: cout << "case3" << endl; break;
		default: cout << "default" << endl;
	}
}

