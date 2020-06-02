#include<iostream>
using namespace std;

class  mut {
public:
int x;
mutable int y;
mut() { x =10; y=20;}
};

int main() {
const mut m;
cout << m.x << endl << m.y << endl;
//m.x=1;
m.y=2;
cout << m.x << endl << m.y << endl;
}
