#include<iostream>
using namespace std;

static void fun() {
static int i=0;
cout << "fun " << ++i << endl;
}

int main() {
fun();
fun();
}
