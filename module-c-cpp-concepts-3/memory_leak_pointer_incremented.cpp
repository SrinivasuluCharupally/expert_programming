#include<iostream>
using namespace std;

int main() {
        int *i = new int[2];
        i[0]=10; i[1]=20;
        cout << i[0] <<" " << i[1] << endl;
        //i++; // if you increment pointer and delete(i) will cause error at runtime, "Invalid pointer"
        delete(i);
}
