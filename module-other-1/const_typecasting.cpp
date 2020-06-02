#include <iostream>
using namespace std;

int main() {
const float f = 2.9;
int i = f;
cout << " i = " << i << endl;
float* j;
j = const_cast<float*>(&f);
cout << " after constant casting i =" << *j << endl;
}
