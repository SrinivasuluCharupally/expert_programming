// Deck of Cards: Design the data structures for a generic deck of cards. Explain how you would subclass the data structures to implement blackjack.


// source 
//https://epicfei.wordpress.com/2013/08/10/7-1-design-the-data-structures-for-a-generic-deck-of-cards-explain-how-you-would-sub-class-it-to-implement-particular-card-games/

#include<iostream>
#include<set>
#include<vector>
#include<cstdlib>

using namespace std;

namespace SUIT {
	enum ENUM {
		SPADE,
		HEART,
		CLUB,
		DIAMOND
	};
};

class Card {
	int v;
	SUIT::ENUM s;
  public:
	Card(int val, SUIT::ENUM e) : v(val), s(e) { }
	virtual SUIT::ENUM suit() {
		return s;
	}

	virtual int val() {
		return v;
	}
};

class BlackJackCard : public Card {
  public:
	BlackJackCard(int val, SUIT::ENUM e) : Card(val,e) { }
	int val() {
		int v = Card::val();
		if(v < 10) return v;
		return 10;
	}
};

class Player {
	int id, bet;
	set<int> points;
	vector<BlackJackCard *> bjcs;

	bool addPoint(set<int>& points, BlackJackCard* card) {
		if(points.empty()) {
			points.insert(card->val());
			if(card->val() == 1) points.insert(11);
		}
		else {
			set<int> tmp;
			for(set<int>::iterator itr = points.begin(); itr != points.end(); ++itr) {
				tmp.insert(*itr + card->val());
				if(card->val() ==1) tmp.insert(*itr + 11);
			}
			points = tmp;
		}
	}

	void getPoints() {
		cout << "You all possible points" << endl;
		for(set<int>::iterator itr = points.begin(); itr != points.end(); ++itr) {
			cout << *itr << " " << endl;
		}
	}
	
	int getMinPoints() {
		return *(points.begin());
	}

	void printCards() {
		cout << "You Card " << endl;
		for(vector<BlackJackCard *>::iterator itr = bjcs.begin(); itr != bjcs.end(); ++itr) {
			cout << (*itr)->val() << " " << endl;
		}
	}


  public:
	Player(int i, int j) : id(i), bet(j) { 
		bjcs.push_back(new BlackJackCard(rand()%13+1, SUIT::SPADE));
		bjcs.push_back(new BlackJackCard(rand()%13+1, SUIT::SPADE));
		addPoint(points, bjcs[0]);
		addPoint(points, bjcs[1]);
	}

	void getAnotherCard() {
		for(set<int>::iterator itr = points.begin(); itr != points.end(); ++itr) {
			if(*itr <= 21 && 21-*itr <=4) {
				printCards();
				getPoints();
				cout << "Stand " << endl;
				exit(1);
			}
		}
		bjcs.push_back(new BlackJackCard(rand()%13 + 1, SUIT::SPADE));
		addPoint(points, bjcs.back());
		if(getMinPoints() > 21) {
			printCards();
			getPoints();
			cout << "Busted " << endl;
			exit(2);
		}
	}

	virtual ~Player() {
		for(vector<BlackJackCard *>::iterator itr=bjcs.begin(); itr!=bjcs.end(); ++itr) {
			delete *itr;
		}
	}
};

int main() {
	srand(time(NULL));
	Player p(1,1000);
	p.getAnotherCard();
	p.getAnotherCard();
	p.getAnotherCard();
	return 0;
}

	
		
 
	
