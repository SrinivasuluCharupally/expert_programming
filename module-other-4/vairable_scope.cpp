#include <iostream>
#include <string>
using namespace std;

int main() {
int x = 20;
cout << "1st loop " << x << endl; {
int x1 = 30;
cout << "2nd loop " << x << endl; {
int x2 =  40 ;
cout << "3rd loop " << x2 << endl;
}
cout << "3rd loop ending " << x1 << endl;
}
cout << "2nd loop ending " << x << endl;
}


