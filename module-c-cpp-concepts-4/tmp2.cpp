#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
using namespace std;

sem_t mySemaphore;

void *f1(void *param) {
        printf("thread %ld\t\t\n", (long)param);
        sem_post(&mySemaphore);
}
void *f2(void *param) {
        sem_wait(&mySemaphore);
        printf("thread %ld\n", (long)param);
}

int main() {
        pthread_t myThread[2];
        sem_init(&mySemaphore, 0, 0);
        long one = 1, two = 2;
        pthread_create(&myThread[0], 0, f1, (void *)one);
        pthread_create(&myThread[1], 0, f2, (void *)two);
        pthread_join(myThread[0], 0);
        pthread_join(myThread[1], 0);
        sem_destroy(&mySemaphore);
}
