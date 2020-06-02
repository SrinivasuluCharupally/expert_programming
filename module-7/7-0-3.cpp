// source http://qa.geeksforgeeks.org/1493/what-is-the-best-way-to-implement-singleton-design-pattern-in
#include<iostream>

using namespace std;

class Singleton {
	int val;
	static Singleton* instance_;
//	Singleton() {}
  public:
	Singleton() {}
	static Singleton* getInstance() {
		if(instance_ ==NULL)  {
			instance_ = new Singleton;
		}
		return instance_;
	}

	void setVal(int d) { val = d; }
	int getVal() { return val; }
};

Singleton* Singleton::instance_ = NULL;

/*
class kk : public Singleton {
public:
 Singleton* kk = Singleton::instance_;
};
*/

int main() {
	Singleton* singletonPointerObj1 = Singleton::getInstance();
        Singleton* singletonPointerObj2 = Singleton::getInstance();
cout << "obj1 = " << singletonPointerObj1 << endl << "Obj2 = " << singletonPointerObj2 << endl;
	Singleton* singletonPointerObj3 = new Singleton;
	cout << "Obj3 = " << singletonPointerObj3 << endl;
}

