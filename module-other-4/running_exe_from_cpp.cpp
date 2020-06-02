// calling a executable from cpp file

#include<iostream>
#include<stdio.h> // sprintf() declared here...
#include<stdlib.h> // system was decleared here

using namespace std; 

int main(int argc, char* argv[]) {
                      char comand[100];
                       sprintf(comand, "./%s", argv[1]);
                                system(argv[1]);
			system(comand);
}
