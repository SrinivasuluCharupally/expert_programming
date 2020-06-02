#include <iostream>
#include <cassert>
using namespace std;

int main() {
int i = 100;
assert( i == 100);
cout << " no assertion" << endl;
assert(false || true);
assert(false);

}
