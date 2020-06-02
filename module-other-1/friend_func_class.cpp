#include <iostream>
using namespace std;

class base {
    private : int pri;
    protected : int pro;
    public : int pub;
    base() : pri(10), pro(20), pub(30) {}
    friend void friend_func(void );
    friend class friend_class;
    void func(void);
};

void friend_func(void) {
   // cout << base::pri << endl; // compiler error, non static, :: works only inheritance + protected
   base b;
   cout << "from friend: private = " << b.pri << " protected = " << b.pro << " public = " << b.pub << endl;
    return;
}

void func(void) {
    base b;
    // cout << b.pri << b.pro << endl;
    cout << "from non friend public = " << b.pub << endl;
    return;
}

class friend_class {
    base b;
    public:
    friend_class() { 
        // cout << base::pri << endl; // compiler error, non static
        cout << "from friend_class: private = " << b.pri << " protected  = " << b.pro << endl;
        
    }
};
int main() {
    friend_func();
    func();
    friend_class f;
}
