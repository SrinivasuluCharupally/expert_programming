//is_same: Implement a template boolean IsSameClass()that takes class A and B as template parameters. It should compare class A and B and return false when they are different classes and true if they are the same class.

#include <iostream>
using namespace std;

template <typename T, typename U> 
struct is_same :  // is_same<T,U> not allowed
std::false_type{};

template <typename T>// <typename T, typename T> not allowed
struct is_same<T,T> : 
std::true_type{};

int main() {
    
    cout << is_same<int, int>::value << endl;
    cout << is_same<int, float>::value << endl;
    return 0;
}