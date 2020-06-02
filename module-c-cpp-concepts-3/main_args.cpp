#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* s[]) {
cout << argc << endl <<  s[1] << endl;
cout << " " << s[2] << endl;
// int k = s[2]; is this is invalid conversion
int k = atoi(s[2]); // atoi = int, atol = long, atof = float
cout << "after convertion=" << atoi(s[2]) <<endl;

 string arg = s[2]; // you should convert argv[] to string then compare...
 if(arg == "-h") { cout << " help option" << endl; }
}
