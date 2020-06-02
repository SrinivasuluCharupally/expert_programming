//Jukebox: Design a musical jukebox using object-oriented principles.


//cpp source https://github.com/S7012MY/Cracking-the-coding-interview/blob/master/7.3.cpp
//java source

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cstring>

using namespace std;

class Song {
	int songId_;
	string songName_, singer_;
public:
	Song(int id, string name, string singer) : songId_(id), songName_(name), singer_(singer) {
	//	++totalCount_;
	}
	Song() {}
	int getCount() {
		static int totalCount_=0;
		++totalCount_;
	}
        int getId() { return songId_; }
	string getName() { return songName_; }
	string getSinger() { return singer_; }
	virtual void addSong(Song* s_) { }
//	virtual vector<Song*> getMyPlayList() {return static_cast<vector<Song*> >(0);}

};

class PlayList : public Song{
	vector<Song*> myPlayList;	
public:
	PlayList(int id, string name, string singer) : Song(id, name, singer) { }
	PlayList() {}
	void addSong(Song* s_) {
		string mysinger_ = "abc";
		if(s_->getSinger() == mysinger_) { 
			myPlayList.push_back(s_);
		}
	}
	int getId() { return Song::getId(); }
	string getName() { return Song::getName(); }
	string getSinger() { return Song::getSinger(); }
	vector<Song*> getMyPlayList() { return myPlayList; }
};


	
class JuckBox {
	Song* s_;
	PlayList p;
	vector<Song*> myLibrary;
public:
	void addSong(int id, string name, string singer) { 
		s_ = new PlayList(id, name, singer);
		p.addSong(s_);
		myLibrary.push_back(s_);
	}
	void displayMyLibraryList() {
		for(vector<Song*>::iterator itr = myLibrary.begin(); itr < myLibrary.end(); ++itr) {
			cout << " Song ID = " << (*itr)->getId() << "Name = " << (*itr)->getName() << "Singer = " << (*itr)->getSinger() << endl;
		}
	}
        void displayMyPlayList() {
//		PlayList pp;
//		PlayList* p;
//		p->getMyPlayList();
		vector<Song*> myPlayList = p.getMyPlayList();
                for(vector<Song*>::iterator itr = myPlayList.begin(); itr < myPlayList.end(); ++itr) {
                        cout << " Song ID = " << (*itr)->getId() << "Name = " << (*itr)->getName() << "Singer = " << (*itr)->getSinger() << endl;
                }
        }

};

int main() {
	JuckBox j;
	j.addSong(20, "abc", "bbc");
        j.addSong(20, "abc", "bbc");
        j.addSong(20, "kbc", "abc");
        j.addSong(20, "kbc", "abc");
        j.addSong(20, "kbc", "abc");

	cout << " My library is " << endl;
	j.displayMyLibraryList();
	cout << "My PLaylist is " << endl;
	j.displayMyPlayList();
}
