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

int main() {
	Singleton* singletonPointerObj1 = Singleton::getInstance();
        Singleton* singletonPointerObj2 = Singleton::getInstance();
cout << "obj1 = " << singletonPointerObj1 << endl << "Obj2 = " << singletonPointerObj2 << endl;
	Singleton* singletonPointerObj3 = new Singleton; // this is possible because constructor is not private, if you make private then it's not possible..
	cout << "Obj3 = " << singletonPointerObj3 << endl;
}

