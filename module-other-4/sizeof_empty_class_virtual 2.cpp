#include<iostream>
using namespace std;
// if we creating empty class then for invocation of empty object required some memory that 
// is why c++ create 1 byte of memory
// for the second one... thatz is already included in the object 
//also to ensure address of two objects of empty class is distinct
// thatz why there is one byte memory
class empty {

};

class emptyWithVirtual {
    public:
    virtual void func(void);
};

int main() {
    cout << "size of empty class is = " << sizeof(empty) << " byte " << endl;
    cout << "size of empty virtual class is = " << sizeof(emptyWithVirtual) << " byte " << endl;
}