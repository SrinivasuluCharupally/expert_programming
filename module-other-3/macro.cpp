// source http://www.tutorialspoint.com/ansi_c/c_preprocessors.htm

#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;


#define PRINT(i,j)  cout << " STR1= " << #i << "STR2 =" << j << endl // # will just print that, the value will be printed
#define QUOTE(s) #s

#ifndef HI
#define HI() cout <<  "helo" << endl
#endif

#define DEBUG true

#ifdef DEBUG 
   int DEBUG_FLAG=20;
#endif

int token34 = 20;

#define tokenpaster(n)  cout << "token" << #n << "= " << token##n << endl

#define LOG(format, ...) \
  fprintf(stdout, "line=%d K=%d P=%u: " format, \
                      __LINE__,  ##__VA_ARGS__);

//#define LOG(fmt, ...)                                                                      \
    fprintf(stderr, __VA_ARGS__);                                                           \


#define eprintf(...) fprintf (stderr, ##__VA_ARGS__)
#define HSA 0

int main() {
 int i=10;
 PRINT("i",i); 
 QUOTE(10);
 HI();
 cout << DEBUG_FLAG << endl;
 tokenpaster(34);
 LOG("hiiiiii", "line: %d P%u:\n", i, i);
 string s = "vargs...";
 int line =20;
 eprintf("\n  %s:%d: \n", s.c_str(), line); // c_str() is used to convert string to char pointer because __VA_ARGS__ accepts only char*
 #if !defined(HSA)
	cout << "defined(HSA)" << endl;
 #endif

} ///:~ 
