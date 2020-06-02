// access member function directly wihtout using class obj

#include<iostream>
using namespace std;

class access {
	int x;
  public:
	access():x(20) {}
  public:
	int get_val() {
		return x;
	}
};

int main() {
	int k = access().get_val();
	cout << " k = " << k << endl;
}
