#include <iostream>
using namespace std;

int main() {
char c;
unsigned char uc;
int i;
unsigned int ui;
short int si;
unsigned short int usi;
unsigned short us;
long int li;
long l;
unsigned long int uli;
unsigned long ul;
float f;
double d;
long double ld;
cout 
<< "\n char = "<< sizeof(c) 
<< "\n unsigned char = "<< sizeof(uc)
<< "\n int =" << sizeof(i)
<< "\n unsigned int = "<< sizeof(ui)
<< "\n short int = " <<sizeof(si)
<< "\n unsigned short int = " << sizeof(usi)
<< "\n unsigned short = " << sizeof(us)
<< "\n long int = " << sizeof(li)
<< "\n long = " << sizeof(l)
<< "\n unsigned long int = " <<sizeof(uli)
<< "\n unsigned long = " <<sizeof(ul)
<< "\n float = " <<sizeof(f)
<< "\n double = " << sizeof(d)
<< "\n long double = "<<sizeof(ld) <<  endl;
}
