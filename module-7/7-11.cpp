// File System: Explain the data structures and algorithms that you would use to design an in-memory file system. Illustrate with an example in code where possible

// source book

#include<iostream>
#include<ctime>

usign namespace std;

class Directory {

};


class File {
	string content_;
	int size;
};

class Entry {
	Directory* directory_;
	long createdTime_;
	long lastUpdatedTime_;
	long lastAcessedTime_;
	string fileName_;

  public:
	Entry(string s, Directory d) {
		clock_t begin = clock();
		double time = begin/CLOCKS_PER_SEC;
		fileName_ = s;
		directory_ = d;
		lastUpdatedTime_ = time;
		lastAcessedTime_ = time;
	}
	
};



	
