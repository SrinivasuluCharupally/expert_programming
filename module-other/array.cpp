#include <iostream>
using namespace std;

int main() {
int a[10];
cout << "sizeof " << sizeof(a) <<endl;
for(int i=0; i<10; i++) {
a[i]=2;
cout << a[i] << endl;
}
}
