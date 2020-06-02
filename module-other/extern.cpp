#include <iostream>
#include "extern_fun.cpp"
using namespace std;

int gv;
void fun();

int main() {
gv=20;
cout <<  " gv inside maim " << gv << endl;
fun();
cout <<  "gv after fun " << gv << endl;
}
