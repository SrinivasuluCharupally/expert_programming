#include<iostream>
using namespace std;

void mul( int a[], int b[]) {
for( int i =0; i<10; i++) {
	int mul = 1;
	for(int j = 0; j < 10; j++) {
		if(i != j) { mul *= (a[j]); }
	}
cout << mul << endl;
b[i] = mul;
}
}

int main() {
int b[10];
int a[10] = {1,2,3,4,5,6,7,8,9,0};
 mul(a, b);
}

