#include<iostream>
#include<stdlib.h>
using namespace std;
typedef enum {a = 1, b=2, c, d} Animal;
int main() {
    Animal value = (Animal)1;
    if(value == a) { cout << "helo" << endl; }
    if(value == 1) { cout << "hi " << endl; }
    if(value == b) { cout << "i am b" << endl; }
}

