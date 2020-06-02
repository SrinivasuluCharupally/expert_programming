// Abstract factory design pattren
// Creates an instance of several families of classes

#include <iostream>
using namespace std;
#define LINUX


class OSBase {
    public:
    virtual void button(void) = 0;
};

class Linux : public OSBase {
    public:
    void button(void) { 
        cout << "Linux Button" << endl;
    }
};

class Win : public OSBase {
    public:
    void button(void) {
        cout << "Windows Button" << endl;
    }
};

class FactoryBase {
    public:
    virtual OSBase *CreateInstance() = 0;
};

class LinuxFactory : public FactoryBase {
    public:
    OSBase *CreateInstance() {
        return new Linux;
    }
};

class WinFactory : public FactoryBase {
    public:
    OSBase *CreateInstance() {
        return new Win;
    }
};

class Client {
    FactoryBase* factoryBaseObj;
 public:
    Client(FactoryBase* f) { factoryBaseObj = f; }
    void button(void) {
        OSBase* oSBaseObj = factoryBaseObj->CreateInstance();
        oSBaseObj->button();
    }
};


int main() {
    FactoryBase* factoryBaseObj;
#ifdef LINUX
    factoryBaseObj = new LinuxFactory;
#endif

Client* clientObj = new Client(factoryBaseObj);
clientObj->button();
}

