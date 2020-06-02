// read by many threads without loc, lock it when wrie

#include<iostream>
#include<pthread.h>
using namespace std;

int shared_data = 0;
pthread_rwlock_t rwvar = PTHREAD_RWLOCK_INITIALIZER;

void* read(void* ) {
	pthread_rwlock_rdlock(&rwvar);
	cout << "read = " << shared_data << endl;
	pthread_rwlock_unlock(&rwvar);
	pthread_exit(0);
}

void* write(void* ) {
	pthread_rwlock_wrlock(&rwvar);
	shared_data = 2;
	pthread_rwlock_unlock(&rwvar);
	pthread_exit(0);
}

int main() {
	pthread_t thread_id[5];
	for(int i =0; i < 4; ++i) 
		pthread_create(&thread_id[i], NULL, read, NULL);
	
	pthread_create(&thread_id[4], NULL, write,NULL);
	void* returntype;
	for(int i = 0; i < 5; ++i) 
		pthread_join(thread_id[i], &returntype);

	pthread_rwlock_destroy(&rwvar);
}
