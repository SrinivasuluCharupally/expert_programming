//Dangling pointer

// source - https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/


//Dangling pointer
//==========================
//A pointer pointing to a memory location that has been deleted (or freed) 
//is called dangling pointer. There are three different ways where Pointer acts 
//as dangling pointer

// 1) De-allocation of memory : Deallocating a memory pointed by ptr causes dangling pointer

#include <stdlib.h>
#include <stdio.h>
int main()
{
    int *ptr = (int *)malloc(sizeof(int));
 
    // After below free call, ptr becomes a 
    // dangling pointer
    free(ptr); 
     
    // No more a dangling pointer
    ptr = NULL;
}

// 2) Function Call : The pointer pointing to local variable becomes dangling when local variable is static.
#include<stdio.h>
 
int *fun()
{
    // x is local variable and goes out of
    // scope after an execution of fun() is
    // over.
    int x = 5;
 
    return &x;
}
 
// Driver Code
int main()
{
    int *p = fun();
    fflush(stdin);
 
    // p points to something which is not
    // valid anymore
    printf("%d", *p);
    return 0;
}
/*
Run on IDE
Output:
A garbage Address
The above problem doesn’t appear (or p doesn’t become dangling) if x is a static variable.
*/

// The pointer pointing to local variable doesn't
// become dangling when local variable is static.
#include<stdio.h>
 
int *fun()
{
    // x now has scope throughout the program
    static int x = 5;
 
    return &x;
}
 
int main()
{
    int *p = fun();
    fflush(stdin);
     
    // Not a dangling pointer as it points
    // to static variable.
    printf("%d",*p);
}
/*
Run on IDE
Output:
5
*/

// 3) Variable goes out of scope
void main()
{
   int *ptr;
   .....
   .....
   {
       int ch;
       ptr = &ch;
   } 
   .....   
   // Here ptr is dangling pointer
}