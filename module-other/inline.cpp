// inline functions ...
// if you notice any issues with inline then use "static inline"
// Clang chooses the "external definition", even when one does not exist in the current CU, 
// leading to an error later during linking. The programmer must ensure an "external definition" 
// is available during linking, either by explicitly providing a definition not marked inline, 
// or by linking in another object with a definition

// source : https://blogs.oracle.com/d/inline-functions-in-c

#include <stdio.h>
inline void foo() 
{
  printf(" In foo\n"); 
}
void main()
{
  foo();
}