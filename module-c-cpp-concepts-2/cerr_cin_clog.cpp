#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
int input;
cout << "Enter number = " ;
cin >> input;

if(cin.good()) {
	cout << input << "It's valid" << endl;
}
else {
	cerr << " Check it " << endl;
}
char c[] = "helooooo ... ";
cerr << "Error :"  << c << endl;
clog << "Error log : " << c << endl;
}
