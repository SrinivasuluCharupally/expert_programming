#include <iostream>
using namespace std;
int* func(void);

int main() {
        int* p = NULL;
    cout << "before int pointer = " << p  << endl;
        char* c = new char[100];
        cout << "before char pointer = " << size_t(c)  << endl;
        p = reinterpret_cast<int*>(c);

        cout << "int pointer = " << size_t(p) << endl << "char pointer = " << c << endl;
        delete(p);
       cout << "after delete int pointer = " << size_t(p) << endl << "after delete char pointer = " << size_t(c) << endl;
       int* p1 = NULL;
       p1 = func();
        cout << "after func call int pointer = " << size_t(p1) << endl;
        cout << "in main  = " << p1[0] << " " << p1[1] << endl; // invalid because it's deleted in func()

        delete(p1); // if you delete in func() and delete here causes double free
        cout << "in main after delete  = " << p1[0] << " " << p1[1] << endl;

        return 0;
}

int* func() {
        int* c = new int[2];
        c[0] = 1; c[1] = 2;
        cout << "in Func = " << c[0] << " " << c[1] << endl;
//      delete(c); // dont delete here because this is used in main()
        return reinterpret_cast<int*>(c);
}

/* output
before int pointer = 0
before char pointer = 47646308801584
int pointer = 47646308801584
char pointer = 
after delete int pointer = 47646308801584
after delete char pointer = 47646308801584
in Func = 1 2
after func call int pointer = 47646308801696
in main  = 1 2
in main after delete  = 0 0

*/