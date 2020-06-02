#include <stdio.h>
#include <stdarg.h>

#define TRACE(...) printf(__VA_ARGS__)
void PrintFError ( const char * format, ... )
{
  char buffer[256];
  va_list args;
  va_start (args, format);
  vsnprintf (buffer,256,format, args);
  perror (buffer);
  va_end (args);
}

int main ()
{
   FILE * pFile;
   char szFileName[]="myfile.txt";

   pFile = fopen (szFileName,"r");
   if (pFile == NULL) {
     PrintFError ("Error opening '%s', %d ",szFileName, 20);
     TRACE("Error opening '%s', %d ",szFileName, 20);
   }
   else
   {
     // file successfully open
     fclose (pFile);
   }
   return 0;
}

/* 
output

Error opening 'myfile.txt': No such file or directory

*/