#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

template<typename T>
class base {
	public:
	virtual void helo() =0;
	virtual T getI() =0;
	//virtual float getI() = 0;
};

template<typename T>
class derive : public base<T> {
	public:
	derive() : i (10) {}
	void helo() { 
		cout <<  i << endl;
	}
	
	T getI() {
                 cout <<  i << endl;
		return i;
	}
		
	T i;

};


//template<typename T>
class container {
  public:
	template<class T>
	void push_back(const T& _t) {
		objs<T>[this].push_back(_t);
	}
	template<class T>
	int getSize() {
		return objs<T>.size();
	}
  public:
	template<class T>
	static std::unordered_map<const container*, std::vector<T> > objs;
//         static std::unordered_map<const container*, std::vector<base<T>> > objs;

};

template<typename T>
std::unordered_map<const container*, std::vector<T> > container::objs;
//std::unordered_map<const container*, std::vector<base<T>> > container::objs;



class XX {
  public:
	XX() { a = 33; }
	virtual float fun1(float) = 0;
	virtual int fun1(int) = 0;
  int a;
};

class X1 : public XX {
  public:
	float fun1(float f = 0.0) { cout << "x1" << endl; }
};

class X2 : public XX {
  public:
	int fun1(int i = 0) { return 10; }
};



template<typename T>
T add(int a, T b, T c);

template<typename T>
base<T> *obj;


template<typename T>
T createObj(T dumy) {
	base<T> *b2 = new derive<T>;
	return b2;
}

typedef union me {
	base<float> *bf;
	base<int> *bi;
}me_t;

std::vector<me_t> vecme;
me_t mebf, mebi;


#include <boost/variant.hpp>
#include <boost/variant/get.hpp>
//#include <variant>

int func(int i = 0) {
	cout << "i am int " << endl;
	return i;
}

float func(float f = 0.0) {
	cout << " i am double" << endl;
	return 12.2;
}

int main() {

XX *x2 = new X2;
float f = 1.2;
//func(1);
func(f);

//cout << "XX::fun1() " << x2->fun1() << endl;
int t = 0;
int k = x2->fun1(t);

mebf.bf = new derive<float>;
mebi.bi = new derive<int>;
vecme.push_back(mebf);
vecme.push_back(mebi);

cout << "using vec union, vecme = " << (vecme[0]).bf->getI() << endl;


//std::vector< std::variant<int, char> > stdvec;
//stdvec.push_back(89);
//stdvec.push_back('s');

//cout << "using std::variant" << std::get<0>(stdvec) << endl; 

std::vector< boost::variant<unsigned, std::string> > vec;
vec.push_back( 44);
vec.push_back(54);
vec.push_back( "str" );
//vec.push_back( SomthingElse(55, 65) );

std::vector< boost::variant<base<float>* , base<int>* > >cont;
unsigned i1 = boost::get<unsigned>(vec[0]);

if(1) {
	cont.push_back(new derive<float>);
	}
else
	cont.push_back(new derive<int>);

base<float> *b1 = new derive<float>;


cout << vec[0] << endl;

//cout << "using boost" << (*cont[0])->getI() << endl;
base<float> *tmp = boost::get<base<float>* >(cont[0]);
//base<float> *tmp1 = boost::get<0>(cont[0]);

cout << "vec get index " << boost::get<unsigned>(vec[0]) << endl;

cout << "using template " << b1->getI() <<endl;
cout << "using boost get obj from container " << cont[0] << endl ;
// cout << "using boost get obj from container " << cont.which() << endl ;
cout << "using boost, get obj method = " << (boost::get<base<float>* >(cont[0]))->getI() << endl;
//cout << "using boost + index, get obj method = " << (get<0>(cont[0]))->getI() << endl;

cout << "using boost get " << boost::get<unsigned>(vec[0]) << endl;

//auto *bt = cont[0];

	container ct;
	ct.push_back(1);
	ct.push_back('c');
	base<float> *bf = new derive<float>;
	XX x;
	cout << "x.a = " << x.a << endl;
	ct.push_back(x);
	ct.push_back(bf);

	for(int i = 0 ; i < ct.getSize<base<float>*>(); i++) { cout << "helo" << endl; }

//	cout << "ct.objs, float " << ct.objs<int>.top() << endl;
	float b = 10.0f;
	float c = 0.0f;
	add(10, b, c);
	if(1)
	obj<float> = new derive<float>;
	else 
        obj<float> = new derive<float>;

 	//base<int> *obj3 = dynamic_cast<base<int> >(new derive<float>);
	
	//cout << b1->i ;
	int i; 
	cout << b1->getI();
	cout << obj<float>->getI();
}

template<typename T>
T add(int a, T b, T c){
 c = a+b;
}
