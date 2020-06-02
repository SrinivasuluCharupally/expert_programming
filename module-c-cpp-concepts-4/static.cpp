#include <iostream>
#include <cstdlib>
using namespace std;

void fun() {
static int i = 0;
cout << i << endl;
i += 1;
}


int main() {
int i = 3;
for(int k=0; k<10; k++)
fun();
}
