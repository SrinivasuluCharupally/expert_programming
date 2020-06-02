#include<iostream>
using namespace std;

class base {
public:
base() { int i = 0; }
int i;
private:
//int i;
};

class derive  {
public:
derive() { }
base b;

private:
//base b;
};

int main() {
derive d;
d.b.i = 10;
cout << d.b.i << endl ;
}
