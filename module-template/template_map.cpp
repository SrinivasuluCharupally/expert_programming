#include <iostream>
#include <map>
using namespace std;

#if 1
template<typename T>
struct wrapper
{
    typedef std::map<int, T> map_type;
};
#endif

template<typename T>
void func(T a) {
	cout << a << endl;
}

int main() 
{

func(10);
func('c');

#if 1
wrapper<string>::map_type mymap;
wrapper<int>::map_type mymap1;
wrapper<string>::map_type::iterator itr;
//mymap::iterator itr;

mymap[1] = "helo";
cout << mymap[1] << endl;

mymap1[1] = 1;
cout << mymap1[1] << endl;

#if 1
         for(itr=mymap.begin(); itr!=mymap.end();itr++)
         {
                 cout << itr->second << endl;
         }
#endif

#endif

}
