// generating  signal which is thread safe using sig_atomic_t

// source :: http://en.cppreference.com/w/cpp/utility/program/signal

#include <csignal>
#include <iostream>
using namespace std;
 
namespace
{
  volatile std::sig_atomic_t gSignalStatus;
}
 
void signal_handler(int signal)
{
  gSignalStatus = signal;
}
 
int main()
{
  // Install a signal handler
  std::signal(SIGINT, signal_handler);
 
  std::cout << "SignalValue: " << gSignalStatus << '\n';
  std::cout << "Sending signal " << SIGINT << '\n';
  std::raise(SIGINT);
  std::cout << " Raised signal#2, SignalValue: " << gSignalStatus << '\n';
}
