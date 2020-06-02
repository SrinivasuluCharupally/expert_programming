#include<iostream>
using namespace std;
class X {
int i;
public:
 X(int x);
void print();
};

X::X(int x) {
i=x;
}

void X::print() {
cout << i << endl;
}

int main() {
X a[2] = {2, 3};

for(int i = 0; i < (sizeof a /sizeof *a); i++) 
a[i].print();
}
