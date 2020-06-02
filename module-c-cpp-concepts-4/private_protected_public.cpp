// access controll 

// source https://stackoverflow.com/questions/5447498/what-are-access-specifiers-should-i-inherit-with-private-protected-or-public

#include<iostream>
using namespace std;

class base {
 private: int pri;
 protected: int pro;
 public: int pub;
 base() : pri(0), pro(1), pub(2) {}
};

class derived : public base {
  public:
	void getprivate() {
		cout << "private = " << " you cant access base::pri " << endl; // this i not allowed because private is accessible only inside base...
	}

	void getprotected() {
		cout << "protected = " << base::pro << endl;
	}

	void getpublic() {
		cout << "public = " << base::pub << endl;
	}
};


class derived2 : protected base { // here inheritance is protected ... 
          //	All Public members of the Base Class become Protected Members of the derived class &
         //All Protected members of the Base Class become Protected Members of the Derived Class.
  public:
        void getprivate() {
                cout << "private = " << " you cant access base::pri " << endl; // this i not allowed because private is accessible only inside base...
        }

        void getprotected() {
                cout << "protected = " << base::pro << endl;
        }

        void getpublic() {
                cout << "public = " << base::pub << endl;
        }
};


int main() {
	derived d; // inheritance is public so you can access protected & public
	d.getprivate();
	d.getprotected();
	d.getpublic();
	cout << "accessing directly base::pub from public inheritance " << d.pub << endl;
          //    All Public members of the Base Class become public Members of the derived class &
         //All Protected members of the Base Class become Public Members of the Derived Class.



	derived2 d2;
        d.getprivate();
        d.getprotected();
        d.getpublic();
//        cout << "accessing directly base::pub from protected inheritance " << d2.pub << endl;
          //    All Public members of the Base Class become Protected Members of the derived class &
         //All Protected members of the Base Class become Protected Members of the Derived Class.


}


