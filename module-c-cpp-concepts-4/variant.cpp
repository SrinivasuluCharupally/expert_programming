#include <variant>
#include <string>
#include <iostream>
#include <map>
using namespace std;

//===============================================================================
// you can not use dynamic iterator on variant, use std::any instead of variant
//===============================================================================


int main()
{
    std::variant<int, std::string, float> v = "abc";
 
    std::cout << "v.index = " << v.index() << '\n';
 
    //v = {}; 
 
    std::cout << "v.index = " << v.index() << '\n';
    std::cout << get<std::string>(v) << endl;
    v = 10;
    std::cout << get<int>(v) << endl;
    v = 1.3f;
    std::cout << get<float>(v) << endl;

    map<int , std::variant<int, std::string, float> > mymap;
    mymap.insert(pair<int, std::variant<int, std::string, float> >(1,1));
    mymap.insert(pair<int, std::variant<int, std::string, float>>(2,1.4f));
    mymap.insert(pair<int, std::variant<int, std::string, float>>(3, "abc"));
    
    
    map<int, std::variant<int, std::string, float> >::iterator itr; 
//===============================================================================
// you can not use dynamic iterator on variant, use std::any instead of variant
//===============================================================================

//    for (itr = mymap.begin(); itr != mymap.end(); ++itr) { 
//        cout << '\t' << itr->first << endl;
//        cout <<  (itr->second) << endl;
//    }

    itr = mymap.begin();
    cout << itr->first << " value " << get<int>(itr->second) << endl;
    itr++;
    cout << itr->first << " value " << get<float>(itr->second) << endl;
    itr++;
    cout << itr->first << " value " << get<std::string>(itr->second) << endl;

    
}
