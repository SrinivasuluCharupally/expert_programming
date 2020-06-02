// birth for only one girl then stop pregnency...
// : In the new post-apocalyptic world, the world queen is desperately concerned about the birth rate. Therefore, she decrees that all families should ensure that they have one girl or else they face massive  nes. If all  milies abide by this policy-that is, they have continue to have children until they have one girl, at which point they immediately stop-what will the gender ratio of the new generation be? (Assume that the odds of someone having a boy or a girl on any given pregnancy is equal.) Solve this out logically and then write a computer simulation of it.


// source book...
#include<iostream>
#include<cstdlib>

using namespace std;

int* runOneFamily();

double runNFamilies(int n) {
	int boys = 0, girls = 0;
	for(int i =0; i < n; ++i) {
		int* genders1 = runOneFamily();
		girls += *genders1;
		boys += *(genders1 + 1); 
	}
        cout << "girls === " << girls << " boys ===" << boys << endl;

	return girls/(double)(girls+boys);
}

int* runOneFamily() {
	int boy = 0, girl = 0;
	while(girl == 0) {
		if(random()%2) 
			girl += 1;
		else 
			boy +=1;
	}
	static int genders[2];
	genders[0]  = girl;
	genders[1] = boy;
	return genders;
}

int main() {
	double percentage = runNFamilies(10);
	cout << "girls ratio is = " << percentage << endl;
}	


