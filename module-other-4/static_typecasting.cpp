#include <iostream>
using namespace std;

int main() {
float f=20.2;
int i = f;
long l = f;
cout << "i = " << i << " l = " << l << endl;
//static 
i = static_cast<int>(f);
l = static_cast<long>(f);
cout << "after casting i =" << i << " after casting l = " << l << endl;
}
