#include <iostream>
#include "extern_example.c"
using namespace std;


extern "C" { print() }
int main() {
    print();
	return 0;
}
