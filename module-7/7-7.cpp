// chat server design


#include<iostream>
#include<vector>
#include<set>

using namespace std;

class User {
        int userId_;
        string userName_;
        int userValidity_;
  public:
        User(int id, string name, int validity) : userId_(id), userName_(name), userValidity_(validity) { }

        int getUserId() { return userId_; }
        string getUserName() { return userName_; }
        int getUserValidity() { return userValidity_; }
        void setUserId(int id) { userId_ = id; }
        void setUserName(string name) { userName_ = name; }
        void setUserValidity(int validity) { userValidity_ = validity; }
};


class UserManager {
        set<int> userIdSet;
        vector<User*> usersQueue;
        User* user;
public:
        void addUser(int id, string name, int validity) {
                pair<std::set<int>::iterator,bool> ret = userIdSet.insert(id);
                if(ret.second != false) {
                        user = new User(id, name, validity);
                        usersQueue.push_back(user);
                }
        }

        void displayUserManager() {
                for(vector<User*>::iterator itr = usersQueue.begin(); itr < usersQueue.end(); ++itr) {
                        cout << "User ID = " << (*itr)->getUserId() << " Name = " << (*itr)->getUserName() << " Validity days = " << (*itr)->getUserValidity() << endl;
                }
        }
        bool isUserValid(int userid) {
                bool is_in = userIdSet.find(userid) != userIdSet.end();
                return is_in;
        }
        int getUserValidity(int userid) {
                for(vector<User*>::iterator itr = usersQueue.begin(); itr < usersQueue.end(); ++itr) {
                        if((*itr)->getUserId() == userid) return (*itr)->getUserValidity();
                }
        }
};


class ChatServer {
	UserManager* userPointerObj;
	vector<int*> oneToOneQueue_;
	vector<int*> oneToManyQueue_;
  public:
	ChatServer() { userPointerObj = new UserManager; }
	void addUser(int id, string name, int validity) {
		userPointerObj->addUser(id, name, validity);
	}
	void oneToOneChat(int id1, int id2) {
		if(userPointerObj->isUserValid(id1) && userPointerObj->isUserValid(id2)) {
			int* p = new int[2];
			*p = id1;
			*(p+1) = id2;
			oneToOneQueue_.push_back(p);
		}
	}
	
	void oneToManyChat(int id1, int id2, int id3) {
		if(userPointerObj->isUserValid(id1) && userPointerObj->isUserValid(id2) && userPointerObj->isUserValid(id3)) {
			int* p = new int[3];
			*p = id1; *(p+1) = id2; *(p+2) = id3;
			oneToManyQueue_.push_back(p);
		}
	}
			
	void displayOneToOneChat() {
		for(vector<int*>::iterator itr = oneToOneQueue_.begin(); itr < oneToOneQueue_.end(); ++itr) {
			cout << " One to one chat b/w user = " << *(*itr) << " , " << *((*itr)+1) << endl;
		}
	}

        void displayOneToManyChat() {
                for(vector<int*>::iterator itr = oneToManyQueue_.begin(); itr < oneToManyQueue_.end(); ++itr) {
                        cout << " One to many chat b/w user = " << *(*itr) << " , " << *((*itr)+1) << ", " << *((*itr)+2) << endl;
                }
        }

	
};

int main() {

        ChatServer chatserverObj;
        chatserverObj.addUser(12, "srinivas", 20 );
        chatserverObj.addUser(13, "amd", 120 );
        chatserverObj.addUser(14, "nv", 220 );
        chatserverObj.addUser(12, "srinivas", 20 );
	chatserverObj.oneToOneChat(12,13);
        chatserverObj.oneToOneChat(12,14);
        chatserverObj.oneToManyChat(12,14,13);
        chatserverObj.oneToManyChat(12,13,14);

        chatserverObj.displayOneToOneChat();
	chatserverObj.displayOneToManyChat();
}
