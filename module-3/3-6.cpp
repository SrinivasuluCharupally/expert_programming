// Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linkedlist data structure.

// Animal shleter problem

//source https://gist.github.com/ThunderXu/5128203

#include<iostream>
#include<list>

using namespace std;

enum Animal {dog = 1, cat};

class AnimalShelter {
	list<Animal> li;

  public:
	void enqueue(Animal);
	void dequeueAny();
	void dequeueDog();
	void dequeueCat();
	void displayAll();
};

void AnimalShelter::enqueue(Animal a) {
	li.push_back(a);
}

void AnimalShelter::dequeueAny() {
	li.pop_front();
}

void AnimalShelter::dequeueDog() {
	list<Animal>::iterator itr = li.begin();
	while(*itr != 1 && itr != li.end()) {
		itr++;
	}
	if(itr != li.end()) {
		li.erase(itr);
	}
}

void AnimalShelter::dequeueCat() {
	list<Animal>::iterator itr = li.begin();
	while(*itr != 2 && itr != li.end()) {
		itr++;
	}
	if(itr != li.end()) {
		li.erase(itr);
	}
}

void AnimalShelter::displayAll() {
	for(list<Animal>::iterator itr = li.begin(); itr != li.end(); ++itr) {
		switch(*itr) {
			case 1:
				cout << "Dog";
				break;
			case 2:
				cout << "Cat";
				break;
			default:
				break;
		}
	}
	cout << endl;
}


int main() {
	AnimalShelter as;
	as.enqueue(cat);
		as.enqueue(dog);
	as.enqueue(cat);
	as.enqueue(cat);
	as.enqueue(dog);
	as.enqueue(cat);
	as.enqueue(cat);
	as.displayAll();
	as.dequeueAny();
	as.displayAll();
	as.dequeueCat();
	as.displayAll();
	as.dequeueDog();
	as.displayAll();
}
