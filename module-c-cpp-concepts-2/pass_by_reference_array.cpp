#include<iostream>
using namespace std;

int  pass_ref(int &i) {
cout << i << endl;
i = 100;
return 0;
}

int pass_value(int i) {
cout << "pass by value" << i << endl;
i = 200;
return 0;
}

int pass_add(int* i) {
cout<< "pass by address" << *i << endl;
*i = 300;
return 0;
}

int main() {
int a[2] = {1,2};
int i = 0;
pass_ref(i);
cout << i << endl;

pass_value(i);
cout << i << endl;

pass_add(&i);
cout << i << endl;
}

