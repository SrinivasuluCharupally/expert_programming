// How signals works... header signal.h
// kill -l to see all available signals

#include <iostream>
#include<signal.h>
using namespace std;

void signal_callback_function(int signalNum) {
    cout << endl << "Caught signal = " << signalNum << endl;
    exit(signalNum);
}
int main() {
    signal(SIGINT, signal_callback_function);
    while(true) { cout << "Loop detected" << endl; }
}

