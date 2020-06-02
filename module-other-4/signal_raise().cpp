// generating a signal when a loop detected or timeout, using raise()
// source : https://www.geeksforgeeks.org/c-signal-handling/

#include <iostream>
#include<signal.h>
using namespace std;

void signal_callback_function(int signalNum) {
    cout << endl << "Caught signal = " << signalNum << endl;
    exit(signalNum);
}
int main() {
    signal(SIGSEGV, signal_callback_function);
    int i = 1;
    while(i) { 
        cout << "Loop detected" << endl; 
        if (i == 5) {
            raise(SIGSEGV);
        cout << "generated signal" << endl; 
        }
        ++i;
    }
}

