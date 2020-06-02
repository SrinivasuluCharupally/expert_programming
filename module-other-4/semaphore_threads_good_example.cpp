#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
using namespace std;

sem_t mySemaphore;

void *f1(void *param)
{
        printf("thread...... \t\t%ld\n", (long)param);
        // signal semaphore
        // increment the value of mySemaphore by 1
        // if there are one or more threads waiting, wake
        sem_post(&mySemaphore);
}

void *f2(void *param)
{
        // wait until value of semaphore is greater than 0
        // decrement the value of semaphore by 1
        sem_wait(&mySemaphore);

        printf("thread %ld\n", (long)param);
}

int main()
{
        pthread_t myThread[2];

        // The 3rd value which is semaphore count set to 0
        sem_init(&mySemaphore, 0, 0);

        long one = 1, two = 2;

        // f2 has sem_wait(), so it should wait
        // until f1 increase the semaphore value to 1
        // As a result, f1 will be executed first
        pthread_create(&myThread[0], 0, f1, (void *)one);
        pthread_create(&myThread[1], 0, f2, (void *)two);

        pthread_join(myThread[0], 0);
        pthread_join(myThread[1], 0);
        sem_destroy(&mySemaphore);
        return 0;
}
