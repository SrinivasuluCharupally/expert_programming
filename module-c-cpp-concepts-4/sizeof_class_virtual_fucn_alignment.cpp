#include <iostream>
using namespace std;
class base {
  int i;
    public:
   //static void func(void);
  virtual void func_base(void) {  }
};

#if 0
void base::func(void) {
    cout << "helo " << endl;
}
#endif

int main() {
    base b;
	cout << sizeof(b)  << endl;
	return 0;
}

// output = 16