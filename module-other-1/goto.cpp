#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
int i;
while(true) {
cout << " enter number :";
cin >> i;
if(i == 10) {
goto bottom;
}
}
bottom: cout << " you got it";
}
