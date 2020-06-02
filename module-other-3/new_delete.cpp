// allocate memory using new and delete

// source 
#include<iostream>

class base {
	int *p;
 public:
	base() {
		p = new int; // allocated inside class so should be deleted inside class , otherwise it's leak
	}

	~base() {
		delete p; // allocated inside class so should be deleted inside class , otherwise it's leak

	}
};

int main() {
	base *b; // this is allocated with in main, should be deleted in main()
	b = new base;
	delete b; // this is allocated with in main, should be deleted in main()
}
