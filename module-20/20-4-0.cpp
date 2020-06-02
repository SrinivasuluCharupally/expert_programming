// factory design pattern
// Creates an instance of several derived classes

#include<iostream>
#include<vector>
using namespace std;

class Person {
    public:
    virtual void personName(void) = 0;
    static Person *storage(int choice);
};

class Srinivas : public Person {
    public:
    void personName(void) {
        cout << "My name is Srinivas" << endl;
    }
};

class Jyothi : public Person {
    public:
    void personName(void ) {
        cout << "My name is Jyothi" << endl;
    }
};

class Pranathi : public Person {
    public:
    void personName(void) {
        cout << "My name is Pranathi" << endl;
    }
};

Person* Person::storage(int choice){
    if (choice == 1) {return new Srinivas; }
    else if (choice == 2) {return new Jyothi;}
        else {return new Pranathi;}
};

int main() {
    int choice;
    std::vector<Person*> storage ;
    while(true) {
        cout << "Enter choice, 0 for exit" << endl;
        cin >> choice ;
        if (choice == 0) break;
        storage.push_back(Person::storage(choice));
    }
    
    for(int i = 0; i < storage.size(); ++i) {
        storage[i]->personName();
    }
}






