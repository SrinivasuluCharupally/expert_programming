#include<iostream>
using namespace std;

class integer {
int i;
public: integer(int ii) : i(ii) { }
	const integer operator+ (const integer& rv) const {
	cout << "operator+" << endl;
	return integer(i + rv.i);
	}
	integer& operator+=(const integer& rv) {
	cout << "operator+=" << endl;
	i += rv.i;
	return *this;
	}
};

int main() {
cout << "built in : " << endl;
int i = 1, j = 2, k = 3;
k += i + j;
cout << " user defined : " << endl;
integer ii(1), jj(2), kk(3);
kk += jj + ii ;
}
