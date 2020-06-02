// functors : 
// source : https://www.quantstart.com/articles/Function-Objects-Functors-in-C-Part-1


/*
A function object allows an instance object of a class to be called or invoked as 
if it were an ordinary function. In C++ this is carried out by overloading operator(). 
The main benefit of using function objects is that they are objects and hence can contain state, 
either statically across all instances of the function objects or individually 
on a particular instance.

Here is a C++ example of a function object (in fact a function object hierarchy), 
which replaces the function pointer syntax from the version above, with functors:
*/

#include <iostream>

// Abstract base class                                                                                                                                                                                                  
class BinaryFunction {
public:
  BinaryFunction() {};
  virtual double operator() (double left, double right) = 0;
};

// Add two doubles                                                                                                                                                                                                      
class Add : public BinaryFunction {
public:
  Add() {};
  virtual double operator() (double left, double right) { return left+right; }
};

// Multiply two doubles                                                                                                                                                                                                 
class Multiply : public BinaryFunction {
public:
  Multiply() {};
  virtual double operator() (double left, double right) { return left*right; }
};

double binary_op(double left, double right, BinaryFunction* bin_func) {
  return (*bin_func)(left, right);
}

int main( ) {
  double a = 5.0;
  double b = 10.0;

  BinaryFunction* pAdd = new Add();
  BinaryFunction* pMultiply = new Multiply();

  std::cout << "Add: " << binary_op(a, b, pAdd) << std::endl;
  std::cout << "Multiply: " << binary_op(a, b, pMultiply) << std::endl;

  delete pAdd;
  delete pMultiply;

  return 0;
}

/*
Firstly, note that there is a lot more happening in the code! 
We have created an abstract base class, called BinaryFunction and then inherited 
Add and Multiply classes. Since BinaryFunction is abstract, it cannot be instantiated. 
Hence we need to make use of pointers to pass in pAdd and pMultiply to the new binary_op 
function.

An obvious question is "What do we gain from all this extra code/syntax?". 
The main benefit is that we are now able to add state to the function objects. 
For Add and Multiply this is likely be to unnecessary. However, if our inheritance 
hierarchy were modelling connections to a database, then we might require information 
about how many connections currently exist (as we wouldn't want to open too many for 
performance reasons). We might also want to add extra database types. An inheritance 
hierarchy like this allows us to easily create more database connection classes without 
modifying any other code.

We have already seen a good use of function objects when we implemented PayOff 
classes in other articles, such as with Asian options pricers via Monte Carlo.
*/