#include <iostream>
using namespace std;

void fun(int a[], int b[]) {
for(int i=0; i<5; i++) {
a[i] = i;
//cout << "fun " << sizeof(a) << " " << a[i] << endl;
}
}
void fun1(int* a) {
cout << "fun1 " << a[3] << endl;
}
int main() {
int a[5], b[5];
fun(a,b);
fun1(a);
cout << "inside main" << a[3] << endl;
}

