#include <iostream>
using namespace std;

void fun(const int &i) {
i = 20;
cout << "inside fun i = " << i << endl;
}

int main() {
const int i=10;
cout << "initial i = " << i << endl;
fun(i);
}
