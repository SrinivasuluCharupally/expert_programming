#include<iostream>
using namespace std;

class pet {
string pname;
public:
pet(const string& name) : pname(name) {}
virtual string name() const { return pname; }
virtual string description() const {
	return "this is " + pname;
}
};

class dog : public pet {
string fav;
public: dog (const string& name, const string& activity)
	: pet(name), fav(activity) {}
string description()  const {
return pet::name() + "likes to " + fav ;
}
};

void describe(pet& p) {
cout << p.description() << endl;
}

int main() {
pet p("alfred");
dog d("fluffy", "sleep");
describe(p);
describe(d);
}
