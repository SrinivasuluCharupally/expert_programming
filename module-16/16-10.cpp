// Living People: Given a list of people with their birth and death years, implement a method to compute the year with the most number of people alive. You may assume that all people were born between 1900 and 2000 (inclusive). If a person was alive during any portion of that year, they should be included in that year's count. For example, Person (birth= 1908, death= 1909) is included in the counts for both 1908 and 1909.


// source book, optimal
#include<iostream>
#include<map>
using namespace std;

class CountingAlive {
	int maxAliveYear;
	int count;
	map<int, int> mymap;
  public:
	void MapBirth(int year) {
		mymap[year] += 1;
	}

	void MapDeath(int year) {
		mymap[year+1] -= 1;
	}
	void FindingYear(){
		int local=0;
		count = 0;
		for(map<int,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr) {
		//	maxAliveyear = itr->first;
			count += itr->second;
			if(local < count) {
				local = count; 
	                        maxAliveYear = itr->first;
			}
		}
		cout << "Max alive year = " << maxAliveYear << " count = " << local << endl;
	}
};

int main() {
	CountingAlive obj;
	obj.MapBirth(12);
        obj.MapBirth(20);
        obj.MapBirth(10);
        obj.MapBirth(1);
        obj.MapBirth(10);
        obj.MapBirth(23);
        obj.MapBirth(13);
        obj.MapBirth(90);
        obj.MapBirth(83);
        obj.MapBirth(75);
	obj.MapDeath(15);
        obj.MapDeath(90);
        obj.MapDeath(98);
        obj.MapDeath(72);
        obj.MapDeath(98);
        obj.MapDeath(82);
        obj.MapDeath(98);
        obj.MapDeath(99);
        obj.MapDeath(94);
        obj.MapDeath(98);
	obj.FindingYear();
}



