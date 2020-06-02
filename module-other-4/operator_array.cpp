//source http://www.cplusplus.com/doc/oldtutorial/templates/ 

#include<iostream>
using namespace std;

//template<class T>
class A {
int A[10];
public: A operator[] (int index) {
	A[index];
	return(A);
}
};

int main() {
//A<int> ia;
//A<float> fa;
A ia;
A fa;
ia[5] = 20;
fa[5] = 1.4;

cout << ia[5] << " " << fa[5] << endl;
}
