#include <iostream>
using namespace std;
class base {
   int i, j, k, l, t ;
    public:
    static void func(void);
    virtual void func_base(void) { //cout << i << endl; 
    }
};

#if 1
void base::func(void) {
    cout << "helo " << endl;
}
#endif

int main() {
    base b;
	cout << sizeof(b)  << endl;
	return 0;
}

// output
32