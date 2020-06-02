// FizzBuzz: In the classic problem FizzBuzz, you are told to print the numbers from 1 to n. However, when the number is divisible by 3, print "Fizz'  When it is divisible by 5, print "Buzz'  When it is divisible by 3 and 5, print"FizzBuzz'  In this problem, you are asked to do this in a multithreaded way. Implement a multithreaded version of FizzBuzz with four threads. One thread checks for divisibility of 3 and prints"Fizz'  Another thread is responsible  r divisibility of 5 and prints"Buzz'  A third thread is responsible  r divisibility of 3 and 5 and prints"FizzBuzz'  A fourth thread does the numbers


// source book


#include<iostream>
#include<pthread.h>
using namespace std;

typedef struct args{
	static const int number=20;
	int div;
} args_t;

void* fizzbuzz(void* args) {
	args_t* local_args = (args_t*)args;
	int div1, div2;
	string s;
	if(local_args->div == 15) {div1 = 3; div2 = 5; s = "fizzbuzz"; }
	else { if(local_args->div == 3) { div1 = 3; div2 = 1; s = "fizz"; }
        	else if (local_args->div == 5) { div1 = 5; div2 = 1; s = "buzz"; }
	}

	for(int i = 0; i < local_args->number; ++i) {
		if(i % div1 == 0 && i % div2 == 0)
		cout << i << " " << s << endl;
	}
	pthread_exit(0);
}


int main() {
	pthread_t thread_id[4];
	args_t args[4];
	args[0].div = 3;
	args[1].div = 5;
	args[2].div = 15;
	args[3].div = 0;
	pthread_create(&thread_id[0], NULL, fizzbuzz, (void*)&args[0]);
        pthread_create(&thread_id[1], NULL, fizzbuzz, (void*)&args[1]);
        pthread_create(&thread_id[2], NULL, fizzbuzz, (void*)&args[2]);
//        pthread_create(&thread_id[3], NULL, fizzbuzz, (void*)&args[3]);
	
	for(int i = 0; i <4; ++i)
		pthread_join(thread_id[i],NULL);

}
	
