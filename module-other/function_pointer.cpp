#include <iostream>
using namespace std;

void  func() {
cout << "inside function" << endl;
}

int main() {
void (*fp) ();//declaration
fp = func; // initialize
(*fp)(); // dereferencing calls the func
void (*fp2) () = func; // declare and initialize
(*fp2)();
cout << "size of func = " << sizeof(func()) << endl;
cout << "address of function=" << fp << endl;
//fp++;i
//cout << "increase address of func" << fp << endl;
}

