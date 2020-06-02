#include<iostream>
using namespace std;

class base {
int i;
public:
base() : i(0) {}
int set(int k) {i = k ;}
void print() { cout << i << endl; }
};

class derive {
int j;
base b;
public:
derive() : j(0) {}
int obj(int x) { b.set(x); }
};

int main() {
derive d;
d.obj(20);
//d.b.print();
}

