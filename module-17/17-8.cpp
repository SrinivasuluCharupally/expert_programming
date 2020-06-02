// Circus  wer: A circus is designing a tower routine consisting of people standing atop one another's shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus, write a method to compute the largest possible number of people in such a tower.

// source own 


#include<iostream>
#include<map>
using namespace std;


map<int,int> mymap = {{65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95} , {74,100}} ;

typedef struct pairing {
	int height;
	int weight;
	pairing* next;
} pairing_t;

bool checkit(int height, int weight, pairing_t* pair) {
	if(height > pair->height && weight > pair->weight) {
		pair->height = height;
		pair->weight = weight;
		return true;
	}
	else return false;
}

int main() {
pairing_t* pairit = new pairing_t;
mymap.insert(pair<int, int>(68,110));
int count  = 0;
for(auto &i : mymap) {
	if(count == 0) { 
		//pairing_t* 
             pairit = new pairing_t;
		pairit->height = i.first;
		pairit->weight = i.second;
		count++;
	}
//	cout << i.first << " " << i.second << endl;
	else {
		if(checkit(i.first, i.second, pairit))
		{ cout << i.first << " " << i.second << endl; }
	}
}
}
