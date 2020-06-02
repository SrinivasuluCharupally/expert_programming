#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
struct node {
int v;
struct node *link;
};

struct node *current = NULL;
struct node *head = NULL;

int main()
{
struct node *tmp, *ptr;
int i;

for(i=0; i<5; i++) {

	if(head == NULL) { 
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->v = i;
	tmp->link = NULL;
	head = current = tmp; }
	else { 
        tmp = (struct node*)malloc(sizeof(struct node));

	tmp->v =i;
	tmp->link = NULL;
	current->link = tmp;
	current = tmp;  }
printf("\n val = %d  tmp = %p start = %p cur = %p ", tmp->v, tmp, head, current);
}
ptr = head;
for(i=0; i<4; i++) {
printf(" \n out val = %d link =  %p start = %p \n", ptr->v, ptr->link, head);
ptr = ptr->link;
}
}
