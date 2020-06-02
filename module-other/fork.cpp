/// @brief creating 1 child process from a parent, the for loop will run for both child and parent
/*
Fork system call use for creates a new process, which is called child process, which runs concurrently with process (which process called system call fork) and this process is called parent process. After a new child process created, both processes will execute the next instruction following the fork() system call. A child process use same pc(program counter), same CPU registers, same open files which use in parent process.

It take no parameters and return integer value. Below are different values returned by fork().

// Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
*/



/// source : http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

/// @brief : source : https://stackoverflow.com/questions/29121628/how-to-create-parallel-child-processes-using-fork


#include<iostream>
#include<unistd.h> // fork was defined in this lib
using namespace std;


int main() {
	pid_t pid;
	fork();
	pid = getpid(); // here following code will be execused for both parent & child....
	for(int i = 0; i < 5; ++i) {
		cout << "process id = " << pid << "value = " << i << endl;
	}

}
