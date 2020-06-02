#include <iostream>
using namespace std;

int dog, cat;
void f(int p) {
cout << "pet id " << p << endl;
}

int main() {
int i, j, k;
cout << " f() location " << (long)&f << endl;
cout << " dog location in hexa" << &dog << endl;
cout << " dog location " << (long)&dog << endl;
cout << " cat location " << (long)&cat << endl;
cout << " i location" << (long)&i << endl;
}
