#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
try {
	if(3<4) throw 1;
	else throw 'x';
}

catch(int k) {
        cout << " Interger exception : " << k << endl;
}
catch(...) {
	cout << "Exception occured : " << endl;
}
}
