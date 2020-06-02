// source : https://www.quantstart.com/articles/Function-Objects-Functors-in-C-Part-1

#include <iostream>

double add(double left, double right) {
    return left + right;
}

double multiply(double left, double right) {
    return left * right;
}

double binary_op(double left, double right, double (*f)(double, double)) {
    return (*f)(left, right);
}

int main( ) {
    double a = 5.0;
    double b = 10.0;

    std::cout << "Add: " << binary_op(a, b, add) << std::endl;
    std::cout << "Multiply: " << binary_op(a, b, multiply) << std::endl;

    return 0;
}
/*
The output from this simple example is as follows:

Add: 15
Multiply: 50

In order for a function to receive a function pointer as a parameter it is necessary to specify its return type (in this case double), the parameter name of the function (in this case f) and the types of all parameters necessary for the function pointer (in this case two double values). We are then able to pass the function pointers into the binary_op function. binary_op then dereferences the function pointer in order to execute the correct function - add or multiply.

While function pointers are simple to use in your code, they do suffer from some significant drawbacks:

Efficiency - Function pointers are inefficient when compared with functors (discussed below). The compiler will often pass them as raw pointers and as such the compiler will struggle to inline the code.
State - Function pointers by themselves are not particularly flexible at storing state. Although it is possible, by using a local static variable within the function, there is only ever one global state for the function itself and as such this static variable must be shared. Furthermore this static variable will not be thread-safe, unless the appropriate thread synchronisation code is added. Thus it can lead to bottlenecks or even race conditions in multithreaded programs.
Templates - Function pointers do not play too well with templates if there are multiple signatures of the function in your code. The solution is to use function pointer casting, which leads to difficult and ungainly syntax.
Adaptation - Function pointers have fixed parameter types and quantities. Thus they are not particularly flexible when external functions with differing parameter types could be used. Although adapting the function pointers (by wrapping the external functions with hard-coded parameters) is possible, it leads to poor flexibility and bloated code.
The solution to these problems is to make use of the C++ function object (also known as a functor)
*/
