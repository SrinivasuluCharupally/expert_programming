/// @brief: demostrate use of __func__ , __FUNCTION__, __PRETTY_FUNCTIOn__


#include<iostream>
using namespace std;


namespace N {
    class C {
        public:
            template <class T>
            static void f() {
                std::cout << __func__ << std::endl
                          << __FUNCTION__ << std::endl
                          << __PRETTY_FUNCTION__ << std::endl;
            }
    };
}

//    N::C::f<int>();

int main(int argc, char **argv)
{
    std::cout << __func__ << std::endl
              << __FUNCTION__ << std::endl
              << __PRETTY_FUNCTION__ << std::endl;

cout << "For class ..." << endl;
    N::C::f<int>() ;

}
