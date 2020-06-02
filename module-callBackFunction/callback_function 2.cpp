//source http://opensourceforu.com/2012/02/function-pointers-and-callbacks-in-c-an-odyssey/

//void LL_callback_function(UL_callback_ptr ul_ptr);


#include<iostream>
#include "callback_library.h"
using namespace std;
//int (*callback)(int,int);

void UL_function(void) {
cout << "I am upper layer function " << endl;
}



int main() {
   LL_add_callback_ptr ll_add_callback_ptr = LL_add;
   LL_2_UL_func_callback_ptr ll_2_ul_func_callback_ptr = LL_2_UL_function;
   cout << "using regular " << LL_add(10,20) << endl;
   cout << "using callback" << ll_add_callback_ptr(10,20) << endl;
   cout << "call low level " ;
ll_2_ul_func_callback_ptr(UL_function);
cout << endl;
}

