#include<iostream>
using namespace std;

class  mut {
public:
int x;
mutable int y;
mut() { x =10; y=20;}
void inc() { x=40;}
};

int main() {
const mut m;
mut m1;
cout << m.x << endl << m.y << endl;
//m.x=1;
m.y=2;
m.y = 4;
m1.inc();
//m.inc(); it gives compiler error because m is a const obj
cout << m.x << endl << m.y << endl;
}
