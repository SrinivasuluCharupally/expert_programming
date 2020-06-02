// this program adds two arrays and copied results to output array, using 4 threads

// the application will crash if i use &i in thread_creation, it shoudl have a shared buffer so i used shared_data[4] which will be used by different thread 

// source http://www.dailyfreecode.com/code/find-sum-numbers-1-n-thread-2111.aspx



#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;


int input1[1000], input2[1000], output[1000]; // for threads it should be global mem
pthread_mutex_t mvar = PTHREAD_MUTEX_INITIALIZER;


void* Addition(void* offset) {
	int *local_offset = (int*)offset;
	for(int i = ((*local_offset) * 250); i < ((*local_offset)+1)*250; ++i) {
	//	pthread_mutex_lock(&mvar);
		output[i] = input1[i] + input2[i];
	//	pthread_mutex_unlock(&mvar);
	}
	pthread_exit(0);
}
	

int main() {

	pthread_t thread_id[4];
	int shared_data[4] = {0,1,2,3};
	void* status;

        fill_n(input1, 1000, 3);
        fill_n(input2, 1000, 4);
        fill_n(output, 1000, 0);

	for(int i = 0; i < 4; ++i) {
		int result = pthread_create(&thread_id[i], NULL, Addition, &shared_data[i]); // &i gives unknown result because "i" memory will be overwritten by ++i and thread_id[0] get different value by the time the thread created... so you should have dedicated memory so that no overwritting by ++i;

		if(result) cout << "Thread creation failed" << endl;
	}
	
	for(int i = 0; i < 4; ++i) {
		int result = pthread_join(thread_id[i], &status);
		if(result) cout << "Join failed " << i << endl;
	}
//	usleep(1000000);

	for(int i =0; i < 1000; ++i)
		cout << i << " " << output[i] << endl;

	//pthread_exit(NULL);
}
