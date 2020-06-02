#include<iostream>
using namespace std;

inline int fac(int n) {
//	if(x<=1) return 1;
//	else { return x*fac(x-1); }
return n ? n*fac(n-1):1;
}

int main() {
cout << fac(5) << endl; 
}


