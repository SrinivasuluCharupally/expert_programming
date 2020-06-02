// this check how to come out of loop using volatile signal type

#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

volatile int signal = 0;

void loop() {
	int i = 1;
	while(signal == 0) {
		cout << "i am looping, waiting for signal " << i << endl;
		++i;
	}
	cout << "signal recieved, exit from looping" << endl;
}

void signal_generator() {
//	this_thread::sleep_for(2);
	usleep(3);
	signal = 1;
}

int main() {
	std::thread looping(loop);
	std::thread signal_gen(signal_generator);
	looping.join();
	signal_gen.join();
}
