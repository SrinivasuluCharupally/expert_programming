// Paint Fill: Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color.

// source book

#include<iostream>
using namespace std;

enum color {red=0, blue, black, green};
color (*FillImage(color[4][4], int, int, color, color))[4];
string colorstring[4] = {"red","blue","black","green"};

int main() {
	color screen[4][4] = 	{{red, blue, black, green},
				 {red, red, red, red},
				 {blue, red, black, green},
				 {green, green, red, red}};
	//color screen2[2][2] = {{red,black}, {blue,green}};
	//cout << screen2[0][1] << " " << screen2[1][0] << endl;

	color oldcolor, newcolor;
	oldcolor = red;
	newcolor = green;
	color (*result)[4];
	cout << "before ..." << endl;
        for(int i =0; i<4; ++i) {
                for(int j = 0; j<4; ++j)
                        cout << "  " << colorstring[screen[i][j]];
                cout << endl;
        }
	result = FillImage(screen, 1, 1, oldcolor, newcolor);
	cout << "after ..." << endl;
	for(int i =0; i<4; ++i) { 
		for(int j = 0; j<4; ++j)
			cout << "  " << colorstring[result[i][j]];
		cout << endl;
	}
	cout << endl;
}

color (*FillImage(color screen[4][4], int row, int col, color oldcolor, color newcolor))[4] {
	if(row < 0 || col <0 || row >= 4 || col >= 4) return NULL;
	if(screen[row][col] == oldcolor) {
		screen[row][col] = newcolor;
		FillImage(screen, row-1, col, oldcolor, newcolor);
		FillImage(screen, row+1, col, oldcolor, newcolor);
		FillImage(screen, row, col-1, oldcolor, newcolor);
		FillImage(screen, row, col+1, oldcolor, newcolor);
	}
	return screen;
}
		
