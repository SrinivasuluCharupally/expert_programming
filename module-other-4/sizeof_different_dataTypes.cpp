// size of different data types.

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i;
	long l;
	long int li;
	long long int lli;
	long long ll;
	double d;
	float f;
	long double ld;
	// long long double lld; invalid scenario, double allowed for long only
	// long float lf; invalid scenario, long not  allowed for float, use double
	cout << "int = " << sizeof(i) << endl;
	cout << "long = " << sizeof(l) << endl;
	cout << "long int = "<< sizeof(li) << endl;
	cout << "long long int = " << sizeof(lli) << endl;
	cout << "long long = " << sizeof(ll) << endl;
	cout << "double = " << sizeof(d) << endl;
	cout << "float = " << sizeof(f) << endl;
	cout << "long double = " << sizeof(ld) << endl;
	cout << "long long double = invalid scenario, long double allowed"  << endl;
	cout << "long float = invalid scenario, use double"   << endl;
	return 0;
}

/* output
int = 4
long = 8
long int = 8
long long int = 8
long long = 8
double = 8
float = 4
long double = 16
long long double = invalid scenario, long double allowed
long float = invalid scenario, use double
*/