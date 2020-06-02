// look all comments..

#include<iostream>
#include<string>
using namespace std;


string* fun(string &s) {
	if(s.length() >= 5) {
		return &s;
	}
	else {
	string* newstring = new string[3];
//	newstring += "h";
	return newstring;
	}
}

void fun2(string s) { s = "hi" ; } // s becomes local , will not change

// void fun2(string* s)  // you cant do this, string has to be passed using string& 

void fun3(char* s) { // this is also not possible
}

int main() {
	string s = "bye";
	string *out = fun(s);
	fun2(s);  // this cant be done, you cant pass string directly, 

	cout << "after fun2 " << s << endl;
//	char* k = s; // this is also not possible...
//	fun3(s); // you cant pass string to char*...
        cout << "after fun3 " << s << endl;
        return 0;

}
