#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void fun(int i) {
cout << "inside fun i = " << i << endl;
i =100;
cout << " inside fun after increment 100 , i = " << i << endl;
}

int main() {
int i=50;
cout << " initial i = " << i << endl;
fun(i);
cout << "after fun i = " << i << endl;
}

