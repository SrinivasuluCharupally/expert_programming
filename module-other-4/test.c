#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>
main(){

  char *str;
  
str = (char *)malloc(14);
		if (str == 0)
		{
			printf("ERROR: Out of memory\n");
			return 1;
		}

strcpy(str, "srinivas");

printf("\nhelo-- %s \n", str);
free(str);
//return (0);

printf("dklfjdjf");
   
   return 0;

}
