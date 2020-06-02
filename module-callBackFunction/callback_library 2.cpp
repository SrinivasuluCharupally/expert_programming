#include<iostream>
#include"callback_library.h"

int LL_add(int a, int b) {
	return a+b;
}

void LL_2_UL_function(backfun ul_ptr) {
ul_ptr();
}

// register a callback function

/*
typedef (*cl_bk)(int, int);

cl_bk cl_bK-play;
void register_calback(backfun ul_Ptr,type)
{
  cl_bk_play = ul_ptr;

}

void LL_2_UL_function() {
cl_bk_play();
}

*/
