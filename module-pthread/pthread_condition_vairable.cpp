// how to use conditional vairable


#include<iostream>
#include<pthread.h>

long shared_data = 10000000000;
pthread_mutex_t mvar = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cvar  = PTHREAD_COND_INITIALIZER;
void* ConditionalCheck(void* ) {
	pthread_mutex_lock(&mvar);
		while(shared_data > 0) 
			--shared_data;
	pthread_mutex_unlock(&mvar);
	
	pthread_cond_signal(&cvar); // use pthread_cond_broadcast() to tell all the threads....
	pthread_exit(0);
}


void* WaitLoop(void* ) {
	std::cout << "Waiting for signal...." << std::endl;

        pthread_mutex_lock(&mvar);
        if(shared_data != 0)
                pthread_cond_wait(&cvar, &mvar);
        pthread_mutex_unlock(&mvar);
	std::cout << "Looping finished, signal recieved ..." << std::endl;
}
	
int main() {
	pthread_t thread_id[2];
	pthread_create(&thread_id[0], NULL, ConditionalCheck, NULL);
	pthread_create(&thread_id[1], NULL, WaitLoop, NULL);
	void* returntype;
	pthread_join(thread_id[0], &returntype);
	pthread_join(thread_id[1], &returntype);
	pthread_mutex_destroy(&mvar);
	pthread_cond_destroy(&cvar);
	return 0;
}

