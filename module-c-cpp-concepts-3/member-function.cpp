#include<iostream>
using namespace std;

class base {
int i;
public:
base() : i(10) {}
int basefun() { int j; }
};
//namespace device {
class Derive {
int j;
public:
int k;
Derive() : k(20) {}
void display()
{
 cout<<"hello i am here"<<endl;
}
int derivefun() { k =0; }
};
//}
int main() {
//derive d;
int i = Derive().k;
Derive().display();
}
