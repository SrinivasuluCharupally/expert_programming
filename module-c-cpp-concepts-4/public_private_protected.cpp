#include<iostream>
using namespace std;

struct A {
public : int i;
private: int j;
};

int main() {
struct A a;
a.i = 10;
cout << a.i << endl;
a.j = 20;
}
