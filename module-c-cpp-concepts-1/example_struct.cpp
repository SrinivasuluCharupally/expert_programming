#include <iostream>
#include "example_struct.h"
#include <cassert>
using namespace std;

const int increment = 100;
void initialize(CS_t* s, int sz) {
s->size = sz;
s->quantity = 0;
s->storage = 0;
s->next = 0;
}

int add(CS_t* s, const void* element) {
if(s->next >= s->quantity) inflate(s, increment);
int startByte = s->next * s->size;
unsigned char* e = (unsigned char*)element;
for(int i = 0; i < s->size; i++) s->storage[startByte + i] = e[i];
s->next++;
return(s->next -1);
}

void* fetch(CS_t* s, int index) {
assert(0 <= index);
if(index >= s->next) return 0;
return &(s->storage[index * s->size]);
}

int count(CS_t* s) {
return s->next;
}

void inflate(CS_t* s, int increase) {
assert(increase > 0);
int newQuantity = s->quantity + increase;
int newByte = newQuantity * s->size;
int oldByte = s->quantity * s->size;
unsigned char* b = new unsigned char[newByte];
for(int i = 0; i < oldByte; i++) b[i] = s->storage[i];
delete [](s->storage);
s->storage = b;
s->quantity = newQuantity;
}

void cleanup(CS_t* s) {
if(s->storage != 0) {
cout << "freeing storage" << endl;
delete []s->storage;
}
}



