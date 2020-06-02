// Pattern Matching: You are given two strings, pattern and value. The pattern string consists of just the letters a and b, describing a pattern within a string. For example, the string catcatgocatgo matches the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab, and b

// source book

#include<iostream>
#include<map>
using namespace std;

map<char, int> mymap;
int psize, vsize;


void FindDiffrentChar(char c[] , int size) {
	for(int i =0; i <size; ++i ) {
		mymap[c[i]] += 1;
	}
}


void PatrenMatch(char value[], char patren[]) {
	FindDiffrentChar(patren, psize);

	int patrencount = mymap.size();
	int pcharsize[patrencount], l=0, i, j;
	for(auto &x: mymap) { pcharsize[l] = x.second; ++l;}
	if(patren[0] == patren[1]) {
		for(i = 1; i < psize; ++i) {
		int x = vsize - (pcharsize[0]*i);
		if((0 == x %pcharsize[1]) && (psize == i+ x/pcharsize[1])) break;
		
		//	if( 0 == x %pcharsize[1] && ((value[0] == value[i]) )) break;
		}
	}
/*	else {
                for(i = 1; i < psize; ++i) {
                int x = vsize - (pcharsize[0]*i);
                        if( 0 == x %pcharsize[1] && ((value[0] == value[psize-i]) || value[1] == value[psize-i])) break;
                }

	}
*/
	cout << "a = " << i << " b = " << (psize - i) << endl;
	mymap.clear();	
}


int main() {
	char value[] = "catcatgocatgo";
	char patren[] ="aabab";
        vsize = (sizeof(value)/sizeof(value[0])) - 1;
        psize = (sizeof(patren)/sizeof(patren[0])) - 1;
	PatrenMatch(value, patren);
	char value1[] = "catgogocatcat";
	char patren1[] = "abbaa";
        PatrenMatch(value1, patren1);

}
