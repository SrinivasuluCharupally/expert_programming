#include<iostream>
#include<iomanip>

using namespace std;

int main() {
cout.precision(7);

float f1 = 334.623505;
float f2 = 334.623505;
float f3 = f1 + f2;
double d = (double)f3;
//double f3 = double(f1 + f2);
cout << f3 << endl;
double d1 = 334.623505;
double d2 = 334.623505;
double d3 = d1 + d2;
float f = (float)d3;
cout << setprecision(10) << d3 << endl;
}
