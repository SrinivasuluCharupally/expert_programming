// A smart pointer is the same as a normal pointer, but it provides safety via automatic memory management. It avoids issues like dangling pointers, memory leaks and allocation failures. The smart pointer must maintain a single reference count for all references to a given object.


// source http://www.geeksforgeeks.org/smart-pointers-cpp/

// source for class object http://ootips.org/yonat/4dev/smart-pointers.html

#include<iostream>
using namespace std;

template<class T>
class SmartPointer {
	T* ptr;
  public:
	explicit SmartPointer(T* p = NULL) { ptr = p; }

	~SmartPointer() { delete ptr; }
 
	T& operator *() { return *ptr; } // carefull, should be T&
	T* operator ->() { return ptr; } // carefull, should be T*
};


class base {
	int b;
  public:
	void setvalue() { b = 100; }
	int getvalue() { return b; }
};

int main() {

	SmartPointer<int> sp(new int); // this is equal to int* sp;
	*sp = 20;
	cout << *sp << endl;

	SmartPointer<base> class_sp(new base); // this is equal to base* class_sp;
	class_sp->setvalue();
	cout << "class_sp->b " << class_sp->getvalue() << endl;
	return 0;
}
