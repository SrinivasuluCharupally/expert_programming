#include<iostream>
using namespace std;

int main() {

try {
if(5>10) { throw 3; }
else { throw 4; }
}

catch(int t) {
cout << t << endl;
}
}
