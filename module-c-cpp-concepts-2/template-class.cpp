#include<iostream>
using namespace std;

template<typename T>
class base {
public:
T  max(T x, T y) {
return x>y?x:y;
}
};

int main() {
base<int> b;
cout << b.max(10,20) << endl;
base<float> f;
cout << f.max(3.4, 1.2) << endl;
}
