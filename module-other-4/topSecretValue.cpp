//Implement a method to get topSecretValue for any given Something* object. 
//The method should be cross-platform compatible and not depend on sizeof (int, bool, string).


#include<iostream>
using namespace std;

class Something {
public:
    Something() {
        topSecretValue = 42;
    }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

class SomethingReplica {
public:
    int getTopSecretValue() { return topSecretValue; }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

int main(int argc, const char * argv[]) {
    Something a; // though topSecretValue is assigned with 42 but you will not SomethingReplica
                // because you dont have getValue() function
    
    SomethingReplica* b = reinterpret_cast<SomethingReplica*>(&a);
    std::cout << b->getTopSecretValue();
}