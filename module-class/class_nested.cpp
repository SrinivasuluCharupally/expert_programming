#include<iostream>
using namespace std;

class Member {
 int i, j, k;
public:
 Member(int x =0) : i(x), j(x), k(x) {}
void fun(int k);
 ~Member() { cout << "~Member=" << i << endl; }
};

void Member::fun(int k) {
i = k;
}

class WithMembers : public Member {
 Member p,r; // Have constructors
 int i;
public:
 WithMembers(int ii) : i(ii) {} // Trivial?
 ~WithMembers() {
 cout << "~WithMembers" <<  endl;
 }
};
int main() {
 WithMembers wm(1);
Member m;
m.fun(3);
wm.fun(4);
} 
