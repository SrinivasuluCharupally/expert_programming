//source http://www.cplusplus.com/doc/oldtutorial/templates/ 

#include<iostream>
using namespace std;

template<class T>
class A {
	T k;
public: 
	void func(T value) {
		k = value;
		cout << "Type is = " << k << endl;
	}
};

template<class T>
void func_template(T i) {
	cout << "From func_template : " << i << endl;
}

int main() {
A<int> ia; // it's an interger obj
A<float> fa; // it's an float obj

ia.func(10);
fa.func(10.123);
func_template(100);
}
