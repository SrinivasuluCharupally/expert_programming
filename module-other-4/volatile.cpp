// the volatile is specifically remove compiler optimization.
// it helps alot when multi threading concepts involved
// one thread waiting and other changing value 
// use "-save-temps" option to dump the assembly, compare *.s with removing volatile from below program, you can see compiler optimization

// source http://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766

#include<iostream>
using namespace std;


int main() {
	int volatile  v = 10;
	while(v == 10) cout << "hi" << endl; // it always true but if other thread updates "v" value then it stops the loop so volatile make sure from compiler side that dont optimize like while(true) , it try to read "v" value all the time

}
