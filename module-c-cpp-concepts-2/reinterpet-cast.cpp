#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
int* a = new int();
void* b = static_cast<void*>(a);
int* c = static_cast<int*>(b);

printf(" a =%p, b = %p , c = %p\n", a,b,c);

int* k = new int();
void* l = reinterpret_cast<void*>(k);
int* m = reinterpret_cast<int*>(l);
printf(" k = %p, l = %p, m = %p \n", k, l, m);
}
