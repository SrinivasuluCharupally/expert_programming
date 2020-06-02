#include<stdio.h>
int func(int, int);
int main(void)
{
    int result1,result2;
    /* declaring a pointer to a function which takes
       two int arguments and returns an integer as result */
    //calling func() 
    int result = func(10,20);
    printf("calling func result = %d\n",result);
    int (*ptrFunc)(int,int);
 
    /* assigning ptrFunc to func's address */                     
    ptrFunc=func;
 
    /* calling func() through explicit dereference */
    result1 = (*ptrFunc)(10,20);
 
    /* calling func() through implicit dereference */         
    result2 = ptrFunc(10,20);               
    printf("explicit result1 = %d \n implicit result2 = %d\n",result1,result2);
    return 0;
}

int func(int x, int y)
{
    return x+y;
}