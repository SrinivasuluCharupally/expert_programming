// Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop () should return the same values as it would if there were just a single stack).
// FOLLOW UP
//	Implement a function popAt(int index) which performs a pop operation on a specific substack.

//soruce ... http://waxworksmath.com/Authors/G_M/Laakmann/Code/c_3_p_3.cpp


#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

class plateStack{
public:
  size_t max_stack_size;
private:
  std::vector< std::stack<int> > stacks_of_plates;
public:
  plateStack(size_t);
  void push(int);
  void pop();
  void popAt(size_t);
};

plateStack::plateStack(size_t mss=3){
  max_stack_size=mss;
}

void plateStack::push(int value){
  if( stacks_of_plates.empty() ){
    // the first element we push
    std::stack<int> my_stack;
    my_stack.push(value);
    stacks_of_plates.push_back( my_stack ); // uses copy constructor
  }else{
    if( stacks_of_plates.back().size() < max_stack_size ){
      stacks_of_plates.back().push(value);
    }else{
      // this stack is full ... create a new one
      std::stack<int> my_stack;
      my_stack.push(value);
      stacks_of_plates.push_back( my_stack );
    }
  }
}

void plateStack::pop(){
  if( stacks_of_plates.empty() ){
    cout << "No elements to pop" << endl;
    assert(0); 
  }else{
    cout << "Popping: " << stacks_of_plates.back().top() << " from last stack" << endl;
    stacks_of_plates.back().pop();
    if( stacks_of_plates.back().empty() ){
      stacks_of_plates.pop_back();
    }
  }
}

void plateStack::popAt(size_t index){
  if( !( index < stacks_of_plates.size() ) ){
    cout << "No elements to pop at index: " << index << endl;
    assert(0);
  }else{
    cout << "Popping: " << stacks_of_plates[index].top() << " from stack " << index << endl;
    stacks_of_plates[index].pop();
    if( stacks_of_plates[index].empty() ){
      cout << "erasing" << endl;
      stacks_of_plates.erase( stacks_of_plates.begin() + index );
    }
  }
}

int main(){
  plateStack ps(2); // no of elements allowed in each stack is 2...
  ps.push(100);
  ps.push(101);
  ps.push(102);
  ps.push(103);
  ps.push(104);
  
  ps.pop();
  ps.pop();
  ps.pop();
  ps.pop();
  ps.pop();

  ps.push(100); // stack 0 
  ps.push(101);
  ps.popAt(0);
  ps.push(102); // onto stack 0
  ps.push(103); // onto stack 1
  //ps.popAt(1);
  //ps.popAt(1);
  ps.push(104); // onto stack 1
  ps.push(105); // onto stack 2
  ps.popAt(1); // remove everything from stack 1
  ps.popAt(1); //
  ps.pop(); // pop from old stack 2 new stack 1

  return 0;
}
