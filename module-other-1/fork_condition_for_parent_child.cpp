/// in this example only piece of code will be execuded from parent and piece of code for child... 

// source  http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

#include<iostream>
#include<unistd.h>
#include<assert.h>

using namespace std;

int main() {
	pid_t pid;
	pid = fork(); // 0 for child, -1 for fai, +ve for parent

	if(pid == 0) { 
		pid_t k = getpid(); cout << "i am child " << k <<  endl; 
		assert(false);
	}

	if(pid >0) { pid_t k = getpid(); cout << "i am parent " << k << endl; }

	usleep(20);
}
