// semaphore, mutex, event, read/write lock are different type of synchronization techniques

// source pthread book


#include<iostream>
#include<semaphore.h>

int shared;
sem_t binary_sem;

void* thread_function(void* arg) {
	sem_wait(&binary_sem);
	sem_signal(&binary_sem);
}


int main() {
	sem_init(&binary_sem,1);
	sem_wait(&binary_sem);
	sem_signal(&binary_sem);
	sem_destroy(&binary_sem);
}
