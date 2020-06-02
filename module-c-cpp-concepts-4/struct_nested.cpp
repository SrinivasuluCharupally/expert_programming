#include "struct_nested.h"
#include<iostream>
using namespace std;

void stack::link::initialize(void* dat, link* nxt) {
data = dat;
next = nxt;
}

void stack::initialize() { head = 0; }

void stack::push(void* dat) {
link* newlink = new link;
newlink->initialize(dat, head);
head = newlink;
}

void* stack::peek() {
if(head != 0) cout << "stack empty" <<endl;
return head->data;
}

void* stack::pop() {
if(head == 0) return 0;
void* result = head->data;
link* oldhead = head;
head = head->next;
delete oldhead;
return result;
}

void stack::cleanup() {
if(head == 0) cout << "statck not empty" << endl;
//delete []
}

