#include<iostream>
using namespace std;

class base {
public:
void	fun_ol(int i) { cout << "int  = " << i << endl; }
void 	fun_ol(float f) { cout << "float = " << f << endl; }
void 	fun_ol(double d) { cout << "double = " << d << endl; }
};

int main() {
base b;
b.fun_ol(10);
b.fun_ol(2.3);
b.fun_ol(34.5633256);
}
