// gives exact CPU clocks 
// source : https://helloacm.com/the-rdtsc-performance-timer-written-in-c/


#include<iostream>
using namespace std;

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main(int argc, char* argv[]) {
  uint64_t tick = rdtsc();  // tick before

    cout << "Helo world" << endl ; // rdtsc will calculate no of cycles between two calls, rdtsc()
  cout << rdtsc() - tick << endl; // difference
  return 0;
}