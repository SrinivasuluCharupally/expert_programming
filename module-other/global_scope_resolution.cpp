#include<iostream>
using namespace std;

int a;
void f() {}

struct s {
int a;
void f();
};

void s::f() {
::f();
::a++; // selects the global a value
a--;	// selects local struct a value
}

int main() {
s s;
f(); 
}
