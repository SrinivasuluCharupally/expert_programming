#include<iostream>
using namespace std;

class pri {
int i;
public:
pri() { i = 10; }
int assign( int k ) { i =k; }
~pri() {cout << i << endl;}
};

int main() {
pri p;
p.assign(20);
p.i = 30;

}
