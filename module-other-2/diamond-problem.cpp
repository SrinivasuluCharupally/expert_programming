#include<iostream>
using namespace std;

class person {
public:
person() {}
virtual void getrole() { cout << "i am person" << endl; }
};

class member : public virtual person {
public:
member() {}
virtual void getrole() { cout << "i am member" << endl; }
};

class student : public virtual person {
public:
student() {}
virtual void getrole() { cout << "i am student" << endl; }
};

class ta : public member, public student {
public:
ta() {}
void getrole() ;
};

int main(){
ta t;
t.getrole();
}

