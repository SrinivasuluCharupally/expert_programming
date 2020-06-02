#include<iostream>
#include<string.h>
using namespace std;

struct my {
int i;
float f;
double d;
} ;

int main() {
my *bar;
my obj;
bar = &obj;
memset(bar, 0, sizeof(bar));
cout <<"bar = " << sizeof(bar) << endl << "*bar = " << sizeof(*bar) <<endl;
}
