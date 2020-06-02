#include<iostream>
using namespace std;

template<typename T>
int fun(T a, T b) {
return a<b?b:a;
}

int main() {
cout << fun(10,20) << endl;
}
