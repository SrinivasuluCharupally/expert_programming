/* Private implementation design pattern (structural design technique)
// source : https://www.codeproject.com/Articles/17536/Use-of-PIMPL-Design-Pattern

PIMPL (Private Implementation) is a simple way to hide a part of a class implementation to other classes of the same project.

It makes it possible to avoid other classes to know internal data structures and other information of the class. It also simplifies some #include preprocessor instructions.

Example WITHOUT PIMPL
We have a CFoo class which is defined in two files foo.h and foo.cpp:

Our main instantiates this class to run one of its functions.
*/

//File foo.h
//Hide   Copy Code
class CFoo
{
public:
    CFoo();
    ~CFoo();
    bool ProcessFile(const CString & csFile);
private:
    CFooInternalData    m_data;
    CHeader             m_header;
} 
File foo.cpp
Hide   Copy Code
#include "FooInternalData.h"
#include "Header.h"
#include "foo.h"
CFoo::CFoo()
{
}

CFoo::~CFoo()
{
}

bool CFoo::ProcessFile(const CString & csFile)
{
    //do something
    return true;
}
Main File
Hide   Copy Code
#include "FooInternalData.h"
#include "Header.h"
#include "foo.h"

int main()
{
    CFoo foo;
    foo.ProcessFile("c:\\data.bin");
    return 0;
} 

//The problem with this simple way of coding is that in your main file, you must include the foo.h to use it, but at the same time you must also include all needed files to allow the compiler to work correctly. In fact, the main does not need to include FooInternalData.h and Header.h (which are CFoo internal structures) except for compilation.... So with very big classes, you might do some huge includes and in this case, you can have some compiler or linker errors because files are already included elsewhere.
//The Same Example with PIMPL
//File foo.h
//Hide   Copy Code

//here just declare the class PIMPL to compile. 
//As I use this class with a pointer, I can use this declaration 
class CFoo_pimpl; 

class CFoo
{
public:
    CFoo();
    ~CFoo();
    bool ProcessFile(const CString & csFile);
private:
    std::auto_ptr<CFoo_pimpl>    m_pImpl;
}  
File foo.cpp
Hide   Shrink    Copy Code
#include "FooInternalData.h"
#include "Header.h"
#include "foo.h"

//here defines PIMPl class, because it is use only in this file
class CFoo_pimpl()
{
public:
    CFoo_pimpl()
    {
    }

    ~CFoo_pimpl()
    {
    }  
    bool ProcessFile(const CString & csFile)
    {
        //do something
        return true;
    }
};

CFoo::CFoo()
:m_pImpl(new CFoo_pimpl())
{
}

CFoo::~CFoo()
{
    //do not have to delete, std::auto_ptr is very nice 
}

bool CFoo::ProcessFile(const CString & csFile)
{
    //just call your PIMPL function ;-)
    return m_pImpl->ProcessFile(csFile);
}
Main File
Hide   Copy Code
#include "foo.h"
int main() 
{
    CFoo foo;
    foo.ProcessFile("c:\\data.bin");
    return 0; 
} 
