#include <iostream>
using namespace std;

typedef struct ss {
int i;
ss *p;
} ss_t;

int main() {
ss_t t1, t2;
int k=0;
t1.i = 10;
t1.p = &t1;
cout << "pointer " << t1.p << "   address of t1 " << &t1 << endl;
}

