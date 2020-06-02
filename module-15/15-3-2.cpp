// Dining philosopher problem

// source http://www.thecrazyprogrammer.com/2017/06/dining-philosophers-problem-c-c.html

#include<iostream>
using namespace std;

int completedPhilo = 0;

typedef struct fork {
	int taken;
} ForkAvil[n];

typedef struct philosp {
	int left, right;
} Philostatus[n];

void goForDinner(int philID) {
	if(Philosatus[philID].left == 10 && Philosatus[philID].right == 10) 
		cout << "Philosopher " << philID+1 << "completed "<< endl;
	else if(Philosatus[philID].left == 1 && Philostatus[philID].right == 1) {
			cout << "Philosopher " << philID+1 <<" completed his dining" << endl;
			Philostatus[philID].left = Philosatus[philID].riht = 10;
			int otherFork = philID - 1;
			if(otherFork == -1) otherFork = (n-1);
			ForAvil[philID].taken = ForkAvil[otherFork].taken = 0;
			cout << "Philosopher " << philID+1 << "released fork "<< philID+1 << "and fork " << otherFork+1 << endl;
			completedPhilo++;
		}
		
		else if(Philostatus[philID].left == 1 && Philosatus[philID].right == 0) {
			if(philID == (n-1)) {
				if(ForkAvil[philID].taken == 0) {
					ForkAvil[philID].taken = Philostatus[philID].right =1;
					cout << "Fork " << philID+1 << " taken by philosopher " << philID+1 << endl;
				}
				else {
					cout << " Philosopher " << philID+1 << "waiting for fork " << philID+1 << endl;
				}
			}
			else {
				int duphilID = philID;
				philID -= 1;
				if(philID == -1) philID = (n-1);
				if(ForkAvil[philID].taken == 0) {
					ForkAvil[philID].taken = Philostatus[dupphilID].right = 1;
					cout <<"Fork " << philID+1 << " taken by Philosopher "<< dupphilID+1 << endl;
				}
				else {
                        cout<<"Philosopher "<<dupphilID+1<<" is waiting for Fork "<<philID+1<<"\n";
				}
		
                    	}

