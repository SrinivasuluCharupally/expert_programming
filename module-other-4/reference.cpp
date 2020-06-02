#include<iostream>
using namespace std;

int y;
int& r =y;

const int& q = 12;
int x = 0;
int& a = x;
int main() {
cout << x << endl << a << endl << r << endl  << q << endl;

}

