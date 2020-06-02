// Call Center: Imagine you have a call center with three levels of employees: respondent, manager, and director. An incoming telephone call must be  rst allocated to a respondent who is free. If the respondent can't handle the call, he or she must escalate the call to a manager. If the manager is not free or not able to handle it, then the call should be escalated to a director. Design the classes and data structures for this problem. Implement a method dispatchCall () which assigns a call to the first available employee.



#include<iostream>
#include<vector>
using namespace std;

class Org {
	int noOfEmp_;
	int noOfMgr_;
	int noOfDct_;
public:
	Org() : noOfEmp_(3), noOfMgr_(2), noOfDct_(2) {}
	void Full() { 
		cout << "Please wait, too many calls today" << endl;
	}

	int getFreeEmp() {
		//--noOfEmp_;
		return noOfEmp_--;
	}
	
	int getFreeMgr() {
		//--noOfMgr_;
		return noOfMgr_--;
	}

	int getFreeDct() {
		//--noOfDct_;
		return noOfDct_--;
	}
	virtual int getId() { return -1; }
	virtual int rank() { return -1; }
};

class Emp : public Org {
	int rank_;
	int Id_;
public:
	Emp(int e) : Id_(e+1) {}
	int rank() {
		return rank_ = Id_*10;
	}
        int getId() {
                return Id_;
        }
		

};

class Mgr : public Org {
	int rank_;
	int Id_;
public:
	Mgr(int m) : Id_(m+1) {}
	int rank() {
		return rank_ = Id_*50;
	}
        int getId() {
                return Id_;
        }

};

class Dct : public Org {
	int rank_;
	int Id_;
public:
	Dct(int d) : Id_(d+1) {}
	int rank() {
		return rank_ = Id_*100;
	}
	int getId() {
		return Id_;
	}
};

class CallHandle {
	Org findResponder;
	vector<Org *> callVector_;
public:
	void getCallHandler() {
		int responder_ = findResponder.getFreeEmp();
		if(responder_ >=0 ) {
			callVector_.push_back(new Emp(responder_));
			return;
		}
		responder_ = findResponder.getFreeMgr();
                if(responder_ >=0 ) {
                        callVector_.push_back(new Mgr(responder_));
                        return;
                }
		responder_ = findResponder.getFreeDct();
                if(responder_ >=0 ) {
                        callVector_.push_back(new Dct(responder_));
                        return;
                }


	}
	void printCallHandler() {
		for(vector<Org *>::iterator itr = callVector_.begin(); itr < callVector_.end(); ++itr) {
			Org* tmp = *itr; // you can do like thi but (*itr)->rank() is correct
			cout << "Emp Id = " << tmp->getId();
			cout << "  his rank =" << (*itr)->rank() << endl;
		//	cout << *itr ;
		}
	}
};

int main() {
	CallHandle call;
	call.getCallHandler();
        call.getCallHandler();
        call.getCallHandler();
        call.getCallHandler();
        call.getCallHandler();

	call.printCallHandler();

}
	
