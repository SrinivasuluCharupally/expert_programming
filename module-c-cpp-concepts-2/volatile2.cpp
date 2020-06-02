#include<iostream>
using namespace std;

class base  {
	bool flag_;
public:
	void wait() {
 	//	while(!flag_) {
//			sleep(100);
	//	}
	}
 void	weakup() volatile  {
		flag_ = true;
	}
};

int main() {
base b;
b.weakup();
volatile base bv;
bv.weakup();
bv.wait();
}
