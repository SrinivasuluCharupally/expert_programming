#include <stdio.h>

int main ()
{
    
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf ("[%s] is a string %d chars long\n",buffer,n);

  
  
  
  char buffer1 [100];
  int cx;
  cx = snprintf ( buffer1, 100, "The half of %d is %d", 60, 60/2 );
  if (cx>=0 && cx<100)      // check returned value
    snprintf ( buffer1+cx, 100-cx, ", and the half of that is %d.", 60/2/2 );
  puts (buffer1);
  return 0;
}

/*
output:

[5 plus 3 is 8] is a string 13 chars long
The half of 60 is 30, and the half of that is 15.

*/