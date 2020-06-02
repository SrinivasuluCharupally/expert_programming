#include<iostream>
using namespace std;


template<typename T>
class base {
T val;
public:
	base(T a) {
		val = a;
	}
	T getval() {
		return val;
	}
};

int main() {
base<int> i(10);
base<float> f(2.3);
cout << "int obj = " << i.getval() << endl << "float obj = " << f.getval() << endl;
}
	
