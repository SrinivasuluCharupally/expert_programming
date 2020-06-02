// MasterMind:TheGameofMasterMindisplayedasfollows:


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

	
