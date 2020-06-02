// Tic Tac Win: Design an algorithm to figure out if someone has won a game of tic-tac-toe.

// souce 

#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

void displayBoard(char* board) {
	for(int i = 0; i < 9; ++i ) {
                if(i%3 == 0) cout << endl;
//		if(board[i] == '-')
//			cout << board ;
		cout << " " << board[i] << " ";
	}
	cout << endl;
}

void displayBoard(int* board) {
        for(int i = 0; i < 9; ++i ) {
                if(i%3 == 0) cout << endl;
//              if(board[i] == '-')
//                      cout << board ;
                cout << " " << board[i] << " ";
        }
        cout << endl;
}

bool gameOver(char* board) {
	for(int i = 0; i < 9; ++i)
		if(board[i] == '-') return false;
	return true;
}
typedef enum turn {COMPUTER=0, HUMAN=1} turn_t;


int main() {
	char board[9];
	turn_t turn = COMPUTER;
	fill_n(board, 9, '-');
	displayBoard(board);
	int in;


	// randomize computer moves;
	int moves[9];
	for (int i=0; i<9; i++)
        moves[i] = i;
    	random_shuffle(moves, moves + 9);


//	displayBoard(moves);
	int computer_index=0;
while(!gameOver(board)) {
		if(turn == COMPUTER) {
   while(board[moves[computer_index]] != '-'){computer_index++;} 
			board[moves[computer_index]] = 'O';
			turn = HUMAN;
			cout << "Computer turn" << endl;
        		displayBoard(board);
	
		}

		else {
			cout << "Your turn, select from 1-9 " ;
			cin >> in;
			board[in-1] = 'X';
			turn = COMPUTER;
		        displayBoard(board);

		}	
	}
}
