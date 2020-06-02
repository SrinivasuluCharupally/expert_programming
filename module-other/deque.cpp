// deque , similar to vector but in vector it's single block of memory, but in deque it's blocks of memory
// advantage is insertion and deletion is const
// deque supported from c++11 onwards so when you compiler use "-std=c++11"

// http://en.cppreference.com/w/cpp/container/deque

#include<iostream>
#include<deque>
using namespace std;

int main() {
	std::deque<int> dq = {1,2,3,4};
	dq.push_back(5);
	dq.push_front(0);
	dq.size();
	for(int i : dq)
		cout << i << endl;
}


