// Null object design pattern (behavioral design techniqe)
//A language with statically typed references to objects illustrates how the null object becomes a more complicated pattern:

class animal 
{
public:
  virtual void make_sound() const = 0;
};

class dog : public animal 
{
  virtual void make_sound() const override 
  { 
      std::cout << "woof!" << std::endl; 
  }
};

class null_animal : public animal 
{
  virtual void make_sound() const override { }
};
/*Here, the idea is that there are situations where a pointer or reference to an animal object is required, but there is no appropriate object available. A null reference is impossible in standard-conforming C++. A null animal * pointer is possible, and could be useful as a place-holder, but may not be used for direct dispatch: a->make_sound() is undefined behavior if a is a null pointer.

The null object pattern solves this problem by providing a special null_animal class which can be instantiated bound to an animal pointer or reference.

The special null class must be created for each class hierarchy that is to have a null object, since a null_animal is of no use when what is needed is a null object with regard to some widget base class that is not related to the animal hierarchy.

Note, that NOT having a null class at all is an important feature, in contrast to languages where "anything is a reference" (e.g. Java and C#). In C++, the design of a function or method may explicitly state whether null is allowed or not.

*/

// function which requires an animal instance,
// and will not accept null
void do_something( const animal& Inst ) {
  // Inst may never be null here
}

// function which may accept an animal instance or null
void do_something( const animal* pInst ) {
  // pInst may be null
}