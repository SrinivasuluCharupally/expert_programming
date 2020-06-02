#include <iostream>
using namespace std;

typedef struct  ss {
int i;
int c;
} ss_t;

int main() {
ss_t t[2];
for(int i=0; i<2; i++) {
t[i].i = i;
}
for(int i=0; i<2; i++) {
cout << t[i].i << endl;
}
cout << "sizeof " << sizeof(t[1]) <<endl;
}
