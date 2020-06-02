// this example checks which thread runs first out of two thread

#include<iostream>
#include<thread>
using namespace std;

void fun(int x) {
	int i = 0;
	while(i < x) {
		cout << i << endl;
		++i;
	}

}

int main() {
	thread first(fun, 30);
	thread second(fun, 10);
	first.join();
	second.join();
}
