//Animal shelter problem
// source : http://fenghaolw.blogspot.in/2014/01/cc150-chapter-3-stacks-and-queues.html

#include<iostream>
#include<list>
#include<queue>
#include<cassert>

using namespace std;

enum AnimalType { cat, dog};

class Animal {
  public: 
	string name;
	AnimalType type;
	Animal(string s, AnimalType t) : name(s), type(t) {}
};

class AnimalShelter {
  private:
	queue<pair<Animal, int> > catShelter;
	queue<pair<Animal, int> > dogShelter;
	int index;
  public:
	AnimalShelter(void) { index = 0; }
	void enqueue(Animal a) {
		if(a.type == cat) {
			catShelter.push(make_pair(a, index));
		}
		else {
			dogShelter.push(make_pair(a,index));
		}
		++index;
	}
	
	Animal dequeueDog(void) {
		assert(!catShelter.empty());
		Animal out = dogShelter.front().first;
		catShelter.pop();
		return out;
	}

	Animal dequeueCat(void) {
		assert(!catShelter.empty());
		Animal out = catShelter.front().first;
		catShelter.pop();
		return out;
	}

	Animal dequeueAny(void) {
		assert(!catShelter.empty() || !dogShelter.empty());
		if(catShelter.empty()) {
			return dequeueDog();
		}
		else {
			if(dogShelter.empty()) {
				return dequeueCat();
			}
			else {
				return (catShelter.front().second > dogShelter.front().second) ? 					dequeueDog() : dequeueCat();
			}
		}
	}
};

int main() {

Animal a("me", "dog");

AnimalShelter kk;
kk.enqueue(a);

}

