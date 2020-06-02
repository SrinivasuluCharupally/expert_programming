#include <iostream>
using namespace std;

int main() {
void *vp;
int i=10;
vp = &i;
cout << "i value " << i << endl;
cout << "i address " << &i << endl;
*(int*)vp = 100;
cout << "i value increased " << i << endl;
}

