/// @brief implementing same class/member function with different namespace

// source 

#include<iostream>
using namespace std;
namespace amd {
	class base{
	 public:
		base() { cout << "namespace amd::base " << endl;}
	};
}

namespace nv {
	class base {
	 public:
		base() { cout << "namespace nv::base " << endl; }
	};
}

int main() {
	amd::base amdb;
	nv::base nvb;

}


