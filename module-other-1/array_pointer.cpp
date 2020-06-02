#include <iostream>
using namespace std;

int main() {
int a[10];
int* p ;
p=a;
for(int i=0; i<10; i++) {
p[i]=i;
}
for(int i=0; i<10; i++) {
cout << a[i] << endl;
}
} 
