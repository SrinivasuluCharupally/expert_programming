// Robot in a Grid: Imagine a robot sitting on the upper le  corner of grid with r rows and c columns. The robot can only move in two directions, right and down, but certain cells are "off limits" such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top le  to the bottom right

#include<iostream>
using namespace std;

bool MoveRobot(int x, int y, int board[3][4]) {
	cout << "x = " << x << " y = " << y << endl;
	if( x==2 && y ==3) { cout << "You reached target! "; return true;}
	if(!board[x+1][y] && !board[x][y+1] && y+1 < 4 && x >=0 ) MoveRobot(x, y+1,board);
	else if(!board[x+1][y] && x < 2)  MoveRobot(x+1, y, board);
}

int main() {
	int board[3][4] = 	{(1, 1, 1, 0),
				 (0, 1, 1, 1),
				 (1, 1, 1, 1) };

	MoveRobot(0,0,board);
}
	
