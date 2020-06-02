#include<iostream>
using namespace std;

int main() {
    int* p = (int*)malloc(sizeof(int));
    cout << "p address = " << p << endl;
    cout << "size_t p = " << size_t(p) << endl;
    
}