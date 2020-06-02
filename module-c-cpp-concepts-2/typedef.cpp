#include<iostream>
using namespace std;

typedef int k, *kp;

int main() {
k v = 10;
kp vp = new int;
*vp = 10;

cout << "v = " << v << endl << "vp = " << *vp << endl;
}
