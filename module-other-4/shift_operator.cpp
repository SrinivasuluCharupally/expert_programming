#include <iostream>
using namespace std;

int main() {
int i=4, j=3, k;
char a ='a', b='b', z;
k=i&j;
z=a&b;
i = z;
cout << "k=" << k << endl;
cout << "z=" << z << "it's value in decimal =" << i << endl;
}
