// operator 

#include<iostream>
using namespace std;
class add {
	int a;
  public:
	add(int v) : a(v) {} 
	add() {}
	add(const add& right) { // copy constructor using call by reference... you can try call by value like add(const add right) { }
		a = right.a;
	}

	add operator+(const add second_right) { // call by value... operator overloading for regular objects... you cant use it for ptr objects... 
		add first_right;
		first_right.a = a + second_right.a;
		return first_right;
	}

        add operator-(const add& second_right) { // call by reference ... operator overloading for regular objects... you cant use it for ptr objects...
                add first_right;
                first_right.a = a - second_right.a;
                return first_right;
        }


	void display() { cout << a ; }
};

int main() {
	add x(3), y(4) ;
	add z;
	z = x+y;
	cout << "operator + overloaded 3+4 =" ; z.display(); cout << endl;
	
        z = x-y;
        cout << "operator - overloaded 3-4 =" ; z.display(); cout << endl;


	add copy_of_x = x;
	cout << "copy constructor & 3 copy to buff" ; copy_of_x.display();
	cout << endl;

}
	


