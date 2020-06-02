// Parking Lot: Design a parking lot using object-oriented principle

// source own & book
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Levels {
	int levels[5];
	int spotsInLevel_;
	int level_;
public:
	Levels() : spotsInLevel_(100), level_(0) {
		for(int i = 0; i < 5; ++i) {
			levels[i] = 0;
		}
	}
	int getFreeLevel() {
		for(int i = 0; i < 5; ++i) {
			if(levels[i] <= 100) {
				return i;
			}
		}
	}

	int freeSpotsInLevel(int l) {
		return levels[l];
	}

	void allocatSpots(int i, int l) {
		levels[l] += i ;
	}
				
};

class Vehicle {
	int vNumber_;
	string vType_;
	bool vHandicap_;
public:
	Vehicle(int n, string s, bool b) : vNumber_(n), vType_(s), vHandicap_(b) {}
	virtual int sportsRequired() {
		return 0;
	}
        int getVehicleNumber() {
                return vNumber_;
        }
        string getVehicleType() {
                return vType_;
        }
        bool getHandicapType() {
                return vHandicap_;
        }

};

class Bike : public Vehicle {
public:
	Bike(int n, string s, bool b) : Vehicle(n,s,b) {}
	int sportsRequired() {
		return 1;
	}
        int getVehicleNumber() {
                return Vehicle::getVehicleNumber();
        }
        string getVehicleType() {
                return Vehicle::getVehicleType();
        }
        bool getHandicapType() {
                return Vehicle::getHandicapType();
        }

};


class Car : public Vehicle {
public:
	Car(int n, string s, bool b) : Vehicle(n,s,b) {}
        int sportsRequired() {
	       return 2;
       	}
        int getVehicleNumber() {
                return Vehicle::getVehicleNumber();
        }
        string getVehicleType() {
                return Vehicle::getVehicleType();
        }
        bool getHandicapType() {
                return Vehicle::getHandicapType();
        }
	

};

class Bus : public Vehicle {
public:
	Bus(int n, string s, bool b) : Vehicle(n,s,b) {}
        int sportsRequired() {
                return 5;
        }

	int getVehicleNumber() {
		return Vehicle::getVehicleNumber(); 
	}
	string getVehicleType() {
		return Vehicle::getVehicleType();
	}
	bool getHandicapType() {
		return Vehicle::getHandicapType();
	}

};

class Parking {
	vector<Vehicle*> vehicleQueue;
	Vehicle* vPointerObj;
	Levels levelObj;
public:
	void vehicle(int n, string s, bool b) {
		if(s == "Bike") vPointerObj = new Bike(n,s, b); 
		else { if(s == "Car") vPointerObj = new Car(n,s, b);
			else if(s == "Bus") vPointerObj = new Bus(n,s, b);
		}
		vehicleQueue.push_back(vPointerObj);
		int spotsRequired = vPointerObj->sportsRequired();
		int level = levelObj.getFreeLevel();
		int freeSpots = levelObj.freeSpotsInLevel(level);
		levelObj.allocatSpots(spotsRequired, level);
	}
	void getAllVehicleDetails() {
		cout << "level filling is " << levelObj.getFreeLevel() << endl;
		cout << "No of sports free in the level " << levelObj.freeSpotsInLevel(levelObj.getFreeLevel()) << endl;
		for(vector<Vehicle*>::iterator itr = vehicleQueue.begin(); itr < vehicleQueue.end(); ++itr) {
			cout << (*itr)->getVehicleNumber() << "  " << (*itr)->getVehicleType() << "  " << (*itr)->getHandicapType() << endl;
		}
	}	
};


int main() {

	Parking park;
	park.vehicle(1111, "Car", false);
        park.vehicle(1112, "Bus", false);
        park.vehicle(1113, "Bike", false);
        park.vehicle(1114, "Car", true);
	park.getAllVehicleDetails();

}

