char* error;
typedef void* handle;

typedef int (*max_t)(int, int);

extern "C" int max(int,int); //// it should match with max_library.so, because it's extern "c", otherwise it will not link..

#define func(k) \
        handle handle_ = dlopen("./libmax_library.so", RTLD_LAZY); \
        if(!handle_) cout << "Fail to open library ..." << endl; \


//cout << #k << endl


