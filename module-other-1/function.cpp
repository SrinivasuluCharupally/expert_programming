#include <iostream>
using namespace std;

char fun(int i) {
	if(i==0)
	return 'a';
	else return 'b';
}


int main() {
cout << "enter number:" ;
int i;
cin >> i;
cout << fun(i) <<endl;
}
