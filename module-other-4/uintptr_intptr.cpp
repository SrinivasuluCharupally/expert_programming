// these are long enough  to store pointer address in signed & unsigned integer..

// The purpose of intptr_t and uintptr_t is that in some applications, you actually do need to do some sort of numeric computation on pointer values, perhaps by flipping individual bits, perhaps by XORing them, etc. In those cases, when you need to work with the numeric value of a pointer, intptr_t and uintptr_t are integer types that (if they exist) are guaranteed to be large enough to hold any pointer. This is not true of, say, int, since int's size relative to pointer sizes isn't specified.

//source https://stackoverflow.com/questions/40941825/understanding-void-against-intptr-t-and-uintptr-t


#include<iostream>

#include<stdint.h>// uintptr_t and intptr_t are part oft stdint.h 
using namespace std;

int main() {
	int value = 0;
	void* cstyle = (void*)&value; //c style
	void* cppstyle = static_cast<void*>(&value); //c++ style
	uintptr_t cuptr = (uintptr_t)(void*)&value; // cstyle, should be &value, uptr would be zero if you try just value.
	//uintptr_t cppuptr = static_cast<uintptr_t>(&value); // this is not allowed, only reinterpret case for uintptr & intptr because these are king of stores integer values not pointer address

	uintptr_t cppuptr = reinterpret_cast<uintptr_t>(&value); //cpp style
	cout << cuptr << endl;

	intptr_t ciptr = (intptr_t)&value; //c++ style
	intptr_t cppiptr = reinterpret_cast<intptr_t>(&value); //cpp style, only reinterpret casting...
	cout << cppiptr << endl;
}
