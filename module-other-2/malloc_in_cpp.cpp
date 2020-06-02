#include<iostream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
int* c = (int*)malloc(sizeof(int));
int* cpp = new int;
*c = 10;
*cpp = 20;
cout << "size of c = " << sizeof(c) << endl << "size of cpp = " << sizeof(c) << endl;
//delete cpp;
//delete c;
cout << "value of c using delete = " << *c << endl << "value of cpp using delete = " << *cpp << endl;
free(c);
free(cpp);
cout << "value of c using free = " << *c << endl << "value of cpp using free  = " << *cpp << endl;

}
