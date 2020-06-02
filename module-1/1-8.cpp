//Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

#include<iostream>
using namespace std;

bool nullifyArray(int*, int);
bool rowNull(int*, int, int);
bool colomNull(int*, int, int);

bool nullifyArray(int* s, int l) {
	int* tracker = new int[l];
	int t = 0;
	for(int i = 0; i < l; ++i) {
		for(int j = 0; j < l; ++j) {
			if(s[i * l + j] == 0) {
				//rowNull(s, i, l);
				//colomNull(s, j, l);
				tracker[t] =  i * l + j;
				++t;
				//break;
			}
		}
	}
	for(int t = 0; t < l; ++t) {
		if(tracker[t] != 0) {
			rowNull(s, tracker[t]/l, l);
			colomNull(s, tracker[t]%l, l);
		}
	}
	return true;
}

bool rowNull(int* s, int i, int l) {
	for(int x = 0; x < l; ++x) {
		s[i * l + x] = 0;
	}
	return true;
}

bool colomNull(int* s, int j, int l)	{
	for(int x = 0; x < l; ++x) {
		s[j + x * l] = 0;
	}
	return true;
}

int main() {
	int s[9] = {1, 2, 3,4,5,0,7,8,9};
	nullifyArray(s, 3);
	int l = 3;
        for(int i = 0; i < l; ++i) {
                for(int j = 0; j < l; ++j) {
			cout << s[i * l +j];
                        
                }
		cout << endl;
        }
}


