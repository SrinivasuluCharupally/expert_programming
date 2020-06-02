// source :https://www.geeksforgeeks.org/template-specialization-c/

// explicit example and issues https://stackoverflow.com/questions/5510922/template-class-specialization


#include <iostream>
using namespace std;

template <class T>
void fun(T a)
{
cout << "The main template fun(): "
		<< a << endl;
}

template<>
void fun(int a)
{
	cout << "Specialized Template for int type: "
		<< a << endl;
}

#include <iostream>
using namespace std;
 
template <class T>
class Test
{
  // Data memnbers of test
public:
   Test()
   {
       // Initialization of data members
       cout << "General template object \n";
   }
   // Other methods of Test
};
 
template <>
class Test <int>
{
public:
   Test()
   {
       // Initialization of data members
       cout << "Specialized template object\n";
   }
};

template<typename T>
struct kk {}; // this important, need base template for explicit template
template<>
struct kk<int> {
    int i;
};

int main()
{
	fun<char>('a');
	fun<int>(10);
	fun<float>(10.14);
	Test<int> a;
    Test<char> b;
    Test<float> c;
    kk<Int> k;
}

/* output
The main template fun(): a
Specialized Template for int type: 10
The main template fun(): 10.14
Specialized template object
General template object
General template object
*/