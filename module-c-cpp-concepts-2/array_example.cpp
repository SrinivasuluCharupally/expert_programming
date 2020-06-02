#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {

int a[] = {1,2,3,4,5,6};
cout << (1+3)[a] << endl;
cout << (a+1)[2] << endl;
cout << (a+1)[0] << endl;
cout << (1+3)[a] - a[0] + (a+1)[2] << endl;
}




