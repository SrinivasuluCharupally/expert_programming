//Q: addition, subtration, multiplication, division without using arthemetic operations, use only bit manupulation....

//source : http://k2code.blogspot.in/2012/01/implement-addsubtractmultiplicationdivi.html


#include<iostream>
using namespace std;

int main() {
	int a = 5, b = 6, c;
	c = a - ~b -1; // addition
	cout << " addition of 5 , 6  =" << c << endl;
	c = a+ ~b +1;
        cout << " subtraction of 5 , 6  =" << c << endl;

	int big = a > b ? a : b;
	int small = a<b?a:b;
	c = 0;
	for(int i =0; i < small; ++i) {
		c += big;
	}
	cout << "Multiplicaiton of 5,6 = " << c << endl;
}


