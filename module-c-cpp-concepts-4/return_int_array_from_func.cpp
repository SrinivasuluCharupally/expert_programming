#include<iostream>
using namespace std;
int* func();
int (*func2dp())[1];
void passing2d2func(int[2][1]);

int main() {
	int a[3] = {1,2,3};
	int* p = func();
	cout << *p << " " << *(p+1) << endl;
//	int a[1][1] = {1,1};
	int (*k1)[1] = func2dp();
	int a2d[2][1] = { 10, 20};
	passing2d2func(a2d);
}

int* func() {
	int a[3] ={1,2,3};
	int* p = a;
	return p; // if you pass "a" here then you see warrning massage saying scopre exceeded
}

int (*func2dp())[1] {
//	int** k i= new int[2][1];
	int k[2][1];
	k[0][0] = 0;
	k[1][0] = 10;
//        int a[2][1] = {1,1};
	int (*r)[1] = k;
	return r; // if you pass "k" here then you see warrning massage saying scopre exceeded
}

void passing2d2func(int a[2][1]) {
	cout << a[0][0] << " " << a[1][0] << endl;
}
