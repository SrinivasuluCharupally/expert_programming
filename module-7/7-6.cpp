// Jigsaw: Implement an NxN jigsaw puzzle. Design the data structures and explain an algorithm to solve the puzzle. You can assume that you have a fitsWith method which, when passed two puzzle edges, returns true if the two edges belong together

// source https://pastebin.com/Y17kvz6n

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class piece {
public:
	int w, h;
	char* data;
  public:
	piece(int w, int h, const char* dat = 0) : w(w), h(h) {
		data = new char[w*h];
		if(dat) memcpy(data, dat, w*h);
		else memset(data, ' ', w*h);
	}
	
	piece& operator = (const piece& p) {
		w = p.w; h = p.h;
		data = new char[w*h];
		memcpy(data, p.data, w*h);
		return *this;
	}
	
	~piece() {
		//delete[] data;
	}

	void print() {
		for(int y=0; y < h; ++y) {
			for(int x = 0; x < w; ++x) {
				cout.put(data[x+y*w]);
			}
			cout.put('\n');
		}
	}

	void turn() {
		char* ndat = new char[w*h];
		for(int x = 0; x< w; ++x)
			for(int y = 0; y < h; ++y)
				ndat[(h-1-y)+x*h] = data[x+y*w];

		delete[] data;
		data = ndat;
		std::swap(w,h);
	}

	bool blit(int px, int py, piece& p) {
		if(px < 0 || py < 0 || px+p.w > w || py+p.h > h) return 0;
		for(int x = 0; x < p.w; ++x) 
			for(int y = 0; y < p.h; y++) 
				if(p.data[x+y*p.w] != ' ' && data[px+x+(py+y)*w]) return 0;

		for(int x =0; x < p.w; ++x)
			for(int y = 0; y < p.h; ++y)
				if(p.data[x+y*p.w] != ' ') 
					data[px+x+(py+y)*w] = p.data[x+y*p.w];

		return 1;
	}
};


bool TryAll(vector<piece> list, piece res) {
	piece result = res;
	for(int a = 0; a < 4; ++a) {
		for(int x = 0; x < result.w; ++x) {
			for(int y = 0; y < result.h; ++y) {
				if(result.blit(x,y,list.back()))
					result.print();
					cout.put('\n');
					bool b = true;
					if(list.size() >1) 
						b = TryAll(vector<piece>(list.begin(), list.end()-1), result);
					if(b) return true;
					else result = res;
			}
		}
	}
	list.back().turn();
		
	return 0;
}

int main(){
        std::vector<piece> list;//here I construct the pieces. normally you would use a file for that.
        list.push_back( piece(3, 1, "###") );
        list.push_back( piece(3, 3, "OOOO  OOO") );
        list.push_back( piece(2, 3, "XXX XX") );
 
        piece result(5, 3);//the jigsaw itself is also a piece.
        //however this piece never holds any value. If you want to change that you could make TryAll return piece*
 
        TryAll(list, result);
 
        std::cin.get();
        return 0;
}
	

