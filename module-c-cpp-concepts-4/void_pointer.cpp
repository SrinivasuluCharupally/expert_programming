#include <string>
#include <iostream>
using namespace std;

int main() {
void *vp;
int i; char c; float f; double d; long l;
vp = &i; cout << "int = " << vp << &vp << endl;
vp = &c; cout << "char = " << vp << &vp << endl;
vp = &f; cout << "float = " << vp << &vp << endl;
}

