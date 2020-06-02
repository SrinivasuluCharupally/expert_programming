//A virtual function depends on a "vtable" or "Virtual Table:' If any function of a class is declared to be virtual, a vtable is constructed which stores addresses of the virtual functions of this class. The compiler also adds a hidden vptr variable in all such classes which points to the vtable of that class. If a virtual function is not  overridden in the derived class, the vtable of the derived class stores the address of the function in its parent class. The vtable is used to resolve the address of the function when the virtual function is called. Dynamic binding in C++ is performed through the vtable mechanism. Thus, when we assign the derived class object to the base class pointer, the vptr variable points to the vtable of the derived class. This assignment ensures that the most derived virtual function gets called.

//In the previous example, speak() is a virtual function in the pet class, so it becomes virtual in each of the derived classes (dog, etc). C++ non-virtual function calls are resolved at compile time with static binding, while virtual function calls are resolved at runtime with dynamic binding.


#include<iostream>
using namespace std;

class pet {
public: virtual string speak() const { return "pet"; }
};

class dog : public pet {
public: string speak() const { return "dog"; }
};

int main() {
dog r;
pet* p1 = &r;
pet& p2 = r;
pet p3;
cout << "p1->speak() " << p1->speak() <<endl;
cout << "p2.speak() " << p2.speak() << endl;
cout << "p3.speak()" << p3.speak() << endl;

pet* base = new dog;
cout << "base->speak()" << base->speak() << endl; //virtual
}

