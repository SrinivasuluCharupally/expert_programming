#include <iostream>
using namespace std;

void fun(int &i) {
cout << "inside fun i = " << i << endl;
cout << " address  i = " << &i << endl;
i =100;
cout << "incrementing to 100 i = " << i << endl;
}


int main() {
int i =  50;
cout << " initial i = " << i << endl;
cout << " address i = " << &i << endl;
fun(i);
cout << " value after fun i = " << i << endl;
}
