typedef int (*LL_add_callback_ptr)(int,int);
typedef void (*backfun)(void);
typedef void (*LL_2_UL_func_callback_ptr)(backfun bf);


int LL_add(int,int);
void LL_2_UL_function(backfun ul_ptr);

