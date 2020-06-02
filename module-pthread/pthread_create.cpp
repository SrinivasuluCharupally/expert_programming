// create thread
/*
* The function to be executed by the thread should take a
* void * parameter and return a void * exit status code .
*/

// source http://homes.dsi.unimi.it/~boccignone/GiuseppeBoccignone_webpage/MatDidatSOD2009_files/pthread-Tutorial.pdf


#include<iostream>
#include<pthread.h>
using namespace std;

void* fun(void* id) {
	cout << " Thread id" << id << endl;
	return NULL;
}


int main() {

	pthread_t threads[5];
	for(int i =0; i < 5; ++i) {
		 int result = pthread_create(&threads[i], NULL, fun, &i);
		if(result) cout << "thread creation failed" << endl;
	}

	pthread_exit(NULL); // make sure the threads completed fully
}
	
