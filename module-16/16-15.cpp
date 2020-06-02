// MasterMind:TheGameofMasterMindisplayedasfollows:The computer has four slots, and each slot will contain a ball that is red (R), yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).You, the user, are trying to guess the solution. You might, for example, guess YRGB.When you guess the correct color for the correct slot, you get a "hit:' If you guess a color that exists but is in the wrong slot, you get a "pseudo-hit:' Note that a slot that is a hit can never count as a pseudo-hit.For example, if the actual solution is RGBY and you guess GGRR , you have one hit and one pseudo­ hitWrite a method that, given a guess and a solution, returns the number of hits and pseudo-hits.


#include<iostream>
using namespace std;

typedef struct help {
	int hit;
	int guess;
} help_t;

class Game {
	help_t help;
	char* compinput = "RGBY";
	
  public:
	Game() { help.hit =0; help.guess = 0; }
	void gameStart(const char* userinput) {
		int count = 0;
		char unused[2], untested[2];
		for(int i =0, l = 0, u=0; i < 4; ++i) {
			if(compinput[i] == userinput[i]) {
				help.hit += 1;
//				userinp[i] = '0';
				//used[u] = userinput[i]; ++u;
			}
			else {
				unused[l] = compinput[i]; ++l;
				untested[u] = userinput[i]; ++u;
				count++;
			}
		}
//                char unused[count], untested[count];
	

		for(int i = 0; i < sizeof(untested)/sizeof(untested[0]); ++i) {
			int tmp = 4-count-1;
			while(tmp > 0) { 
				if(untested[i] = unused[tmp--] )
					help.guess++;
			}
		}
	}
	void display() {
		cout << "No of hits = " << help.hit << endl;
		cout << "No of gues = " << help.guess <<endl;
	}

};

int main() {
	Game obj;
	const char* input = "BGRY";
	obj.gameStart(input);
	obj.display();
}

	

