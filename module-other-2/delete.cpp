#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int* k = new int;
	*k = 20;
	cout << "single chunk memory k = " << *k << endl;
	delete k;
        cout << "single chunk memory after Delete k = " << *k << endl;
	int* chunk = new int[10];
	for(int i =0; i<10; i++) {
	*chunk = i*10; 
//	chunk++;
	cout << "chunk " << i << " = " << *chunk << endl;
	chunk++;
	}
	delete[] chunk;
        for(int i =0; i<10; i++) {
        cout << "chunk " << i << " = " << *chunk << endl;
        chunk++;
        }

}



