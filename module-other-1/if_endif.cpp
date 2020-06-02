#include<iostream>

using namespace std;

#define KK 0

int main() {
	cout << "Hello" << endl;
	#if 1
	cout << "Inside #if #endif " << endl;
	#endif
	#if KK
	cout << "#if Macro " << endl;
	#endif
	#ifdef KK
	cout << "#ifdef Macro " << endl;
	#endif
}
