// sum of n numbers...

// source http://www.dailyfreecode.com/code/find-sum-numbers-1-n-thread-2111.aspx


#include<iostream>
#include<pthread.h>
using namespace std;

int Sum=0;
pthread_mutex_t mvar = PTHREAD_MUTEX_INITIALIZER;

void* sum(void* n) {
	for(int i = *((int*)n);  i <= 10; i += 2) {
		pthread_mutex_lock(&mvar);
		Sum += i;
		pthread_mutex_unlock(&mvar);
	};
	pthread_exit(0);
}

int main() {

	pthread_t thread_id[2];
	int k = 1, l = 2; // should be stored in variable to pass to thread to share data ..
	pthread_create(&thread_id[0], NULL, sum,&k); // you cant pass (void*))1
	pthread_create(&thread_id[1], NULL, sum, &l); // you cant pass (void*)2
	pthread_join(thread_id[0],NULL);
	pthread_join(thread_id[1],NULL);
//	pthread_exit(0);
	cout << "Total" << Sum << endl;
	pthread_mutex_destroy(&mvar);
}

