#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<sstream> // for stringstream
#include<iomanip> // for setprecision
#include<math.h>
using namespace std;


int main() {

//std::setprecision(10);

   double d = 0.12345678910;
   std::cout<<std::fixed; // provide more precision, else 0 will be truncated

   cout << "helo " << setprecision(12) << d << endl;

    double pi;
    pi = 4*atan(1.0);
    cout<<setprecision(30)<<pi;
    
    
    string s = to_string(d);
    cout << s.at(3) << endl;
   // char* p1 = itoa(l);
   int x = atoi("12");
   
   string s1 = "1234";
stringstream x1(s1); // #include<sstream>, moving s to x
int i1 = 0;
x1>>i1;
cout << i1 << endl;


}
