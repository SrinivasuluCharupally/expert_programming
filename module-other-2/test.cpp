#include<iostream>
#include<vector>
using namespace std;

template <typename T>
	T sum(T a, T b) {
		return a+b;
	}

template <typename T>
	class temp {
		private:
		T i;
		public:
		temp() : i(10) {}
		T mul(T a, T b) {
			return a*b+i;
		}
	};

int main() {
vector<int> vec;
cout << sum(10 ,20) << endl;
cout << sum(1.3, 2.5) << endl;
temp<int> i;
temp<float> f;
cout << i.mul(2,3) << endl;
cout << f.mul(2.6, 1.2) << endl;
vec.push_back(10);
vec.push_back(20);
for(vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
cout << "using iterator " << *itr << endl;
}

for(int i=0; i<vec.size(); i++) {
cout << "using size" << vec[i] << endl;
}

}

