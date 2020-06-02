#ifndef STACK_H
#define STACK_H
struct stack {
	struct link {
		void* data;
		link* next;
		void initialize(void* dat, link* nxt);
	}* head;
void initialize();
void push(void* dat);
void* peek();
void* pop();
void cleanup();
};
#endif
