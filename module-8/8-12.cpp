// Eight Queens:Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all diagonals, not just the two that bisect the board.


// source book
// this is not yet compiled, but logic works, not optimized code
// col[8] stores queen position in each colom, supposes col[2] = 4 then queen is located at row 4th in colom 2


#include <iostream>
#include <stdlib.h>
using namespace std;

#define ROW_SIZE 8
#define COL_SIZE 8

int emptycells[8];



FindPossibleWaysOfPossition(int* col) {
    int* col = new int[8];
    int row;
    for(int k = 0; k < 8; ++k ) {
        for(row = 0; row < k; ++i) {
            emptycells[col[row]] = -1;
            int distance =  k - row;
            emptycells[col[row] + distance] = -1;
            emptycells[abs(col[row] - distance)] = -1;
        }
        int i = 0, count = 0, pos;
        //while(emptycells[i] != -1) { ++i; }
        int compare[8]; for(int i = 0; i<8; ++i) compare[i] = -1;
        for(vector<int*>::iterator itr = storage.begin(); itr != storage.end(); ++itr) {
           compare[x] = (*itr)[k]; x++; count++;
        }
        while(emptycells[compare[x]] == -1) x++;
        while(i <8 ) { 
            if(emptycells[i] != -1) { int m = count;
                while(m > 0 ) { if(compare[m] == i) break; m--; }
                pos = i;
            }  
            
        }
        col[k] = pos;
    }
    std::vector<int*> storage;
    storage.push_back(col);
}


int main() {
	
    int result = FindAllWays();
    cout << "No of ways for 8x8 board is = " << result << endl;
	return 0;
}

