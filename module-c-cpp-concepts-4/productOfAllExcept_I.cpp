//Implement a void function F that takes pointers to two arrays of integers (A and B) 
//and a size N as parameters. It then populates B where B[i] is the product of all A[j] where j != i.

//For example: If A = {2, 1, 5, 9}, then B would be {45, 90, 18, 10}.

#include<iostream>
using namespace std;

void F(int* A, int* B, int N) {
    // Set prod to the neutral multiplication element
    int prod = 1;
    
    for (int i = 0; i < N; ++i) {
        // For element "i" set B[i] to A[0] * ... * A[i - 1]
        B[i] = prod;
        // Multiply with A[i] to set prod to A[0] * ... * A[i]
        prod *= A[i];
    }
    
    for(int i = 0; i < 6; ++i) cout << B[i];
     
    // Reset prod and use it for the right elements
    prod = 1;
    
    for (int i = N - 1; i >= 0; --i) {
        // For element "i" multiply B[i] with A[i + 1] * ... * A[N - 1]
        B[i] *= prod;
        // Multiply with A[i] to set prod to A[i] * ... * A[N - 1]
        prod *= A[i];
    }
}

int main() {
    int a[] = {2,3,4,5,0,6};
    int b[6];
    F(a,b,6);
    for(int i = 0; i < 6; ++i) cout << endl << b[i] << endl;
}