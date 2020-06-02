// builder design pattren.
// In this use same object of the class and build it using the inputs provided by the user
// it's best use when you want to build a queue/stack/list based on user inputs

#include <iostream>
#include <string.h>
using namespace std;

class Distributor {
    char *_name, *_type;
    string _namestr, _typestr;
  public:
    void setName(char* p) {
        string str(p);
        _namestr += str;
    }
    string getName(void) {
        return _namestr;
    }
    void setType(char* p) {
        string str(p);
        _typestr += str;
    }
    string getType(void) {
        return _typestr;
    }
};

class BuilderBase {
 protected:
 Distributor *_distributorObj;
 
 public: 
 virtual void configureName(char*) = 0;
 virtual void configureType(char*) = 0;
 string getName(void) {
     _distributorObj->getName();
 }
 string getType(void) {
     _distributorObj->getName();
 }
 
};

class KitchenBuilder : public BuilderBase {
  public:
    KitchenBuilder() {
        _distributorObj = new Distributor();
    }
    void configureName(char* p) {
        _distributorObj->setName(p);
    }
    void configureType(char* p) {
        _distributorObj->setType(p);
    }
};

class HomeBuilder : public BuilderBase {
  public:
    HomeBuilder() {
        _distributorObj = new Distributor;
    }
    void configureName(char* p) {
        _distributorObj->setName(p);
    }
    void configureType(char* p) {
        _distributorObj->setType(p);
    }
};

class Reader {
    BuilderBase *_builderBaseObj;
  public:
    void setBuilder(BuilderBase* b) {
        _builderBaseObj = b;
    }
    void configure(char *arr[]) {
        if(arr[0] == "name") _builderBaseObj->configureName(arr[0]);
        else _builderBaseObj->configureType(arr[1]);
    }
};

char *arr[] = {"name", "type", "name"};

int main() {
    KitchenBuilder kitchenBuilderObj;
    //HomeBuilder *homeBuilderObj;
    Reader readerObj;
    readerObj.setBuilder(&kitchenBuilderObj);
    //readerObj->setBuilder(homeBuilderObj);
    readerObj.configure(arr);
    cout << kitchenBuilderObj.getName() << endl;
    
}




