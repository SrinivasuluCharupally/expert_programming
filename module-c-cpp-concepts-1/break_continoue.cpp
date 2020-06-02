#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(){
char c;
while(true) {
cout << " l  left menu, r right menu, q  quite " << endl;
cin >> c;
if( c == 'q') break;
if( c == 'l'){ cout << "selected left menu" << endl; continue;}
else { cout << " selected right menu " << endl; continue; }
}
cout << " you quite ";
}

