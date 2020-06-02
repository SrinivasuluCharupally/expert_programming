#include <iostream>
using namespace std;

union un {
int i;
double d;
long l;
};

int main() {
cout << "sizeof uniio " << sizeof(un) <<endl;
}

