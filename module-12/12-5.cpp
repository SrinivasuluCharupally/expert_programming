// deep copy and shallow copy
// source https://www.youtube.com/watch?v=nCAVr_T4DbMhttps://www.youtube.com/watch?v=nCAVr_T4DbM

#include<iostream>
using namespace std;

class shallow { // in shallow the pointer point to same data reference
	int a, b;
	int *p;
  public:
	shallow() { }
	shallow(shallow &obj) { // it's copy constructor
		a = obj.a; b = obj.b; p = obj.p;
	}
	void setvalue(int k, int l, int m) {
		a = k; b = l;
		p = new int;
		*p = m;
	}

	void printvalue() {
		cout << "a = " << a << " b = " << b << " *p = " << *p << " p addres = " << p << endl;
	}
};

class deep {
	int a, b;
	int* p;
  public:
	deep() { }
	deep(deep &obj) { // it's deep copy constructor, allocate memory
		a = obj.a; b = obj.b; 
		p = new int;
		*p = *obj.p;
	}
	void setvalue(int k, int l, int m) {
		a = k; b = l;
		p = new int;
		*p = m;
	}

        void printvalue() {
                cout << "a = " << a << " b = " << b << " *p = " << *p << " p addres = " << p << endl;
        }
};


int main() {
	shallow obj1;
	obj1.setvalue(2,3,4);
	shallow obj2 = obj1; // it's shallow copy because *p points to the same reference where the 4 is stored, i mean same address
	cout << "shallow copy obj1 values " ;
	obj1.printvalue();
	cout << "shallow copy obj2 values ";
	obj2.printvalue();
	cout << "shallow copy *p pointing to same address" << endl;



        deep deep_obj1;
        deep_obj1.setvalue(2,3,4);
        deep deep_obj2 = deep_obj1; // it's shallow copy because *p points to the same reference where the 4 is stored, i mean same address
        cout << endl << "deep copy obj1 values " ;
        deep_obj1.printvalue();
        cout << "deep copy obj2 values ";
        deep_obj2.printvalue();
        cout << "deep copy *p pointing to different  address" << endl;


}

