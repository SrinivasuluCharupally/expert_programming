#include<iostream>
using namespace std;

class base1 {
public: ~base1() { cout << "~base1 " << endl; }
int f() { cout << " base1 f " << endl; }

};

class der1 : public base1 {
public: ~der1()  { cout << " ~der1 " << endl; }
int f() { cout << " der1 f " << endl; }

};

class base2 {
public: virtual  ~base2()=0; // { cout << "~base2 " << endl;
virtual int f() { cout << " base2 f " << endl; }

};
base2::~base2() {
cout << "~base2 " << endl;
}

class der2 : public base2 {
public: ~der2()  { cout << " ~der2 " << endl; }
int f() { cout << " der2 f " << endl; }

};

int main() {

base1* bp = new der1;
bp->f();
delete bp;
base2* b2 = new der2;
b2->f();
delete b2;

}


