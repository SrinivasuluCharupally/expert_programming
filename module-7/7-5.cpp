// Online Book Reader: Design the data structures for an online book reader system.


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

class Book {
	int bookId_;
	string bookName_;
	string bookAuthor_;
  public:
	Book(int id, string name, string author) : bookId_(id), bookName_(name), bookAuthor_(author) { }
	int getBookId() { return bookId_; }
	string getBookName() { return bookName_; }
	string getBookAuthor() { return bookAuthor_; }
	void setBookId(int id) { bookId_ = id; }
	void setBookName(string name) { bookName_ = name;}
	void setBookAuthor(string author) { bookAuthor_ = author; }
};


class BookManager {
	set<int> bookIdSet;
	vector<Book*> bookQueue;
	Book* book;
  public:
	
	void addBook(int id, string name, string author) {
		pair<set<int>::iterator, bool> ret = bookIdSet.insert(id);
		if(ret.second) {
			book = new Book(id, name, author);
			bookQueue.push_back(book);
		}
	}

	void displayBookManager() {
		for(vector<Book*>::iterator itr = bookQueue.begin(); itr < bookQueue.end(); ++itr) {
			cout << "Book id = " << (*itr)->getBookId() << " Name = " << (*itr)->getBookName() << " Author = " << (*itr)->getBookAuthor() <<endl;
		}
	}
	bool isBookAvailable(int bookid) {
		bool is_in = bookIdSet.find(bookid) != bookIdSet.end();
		return is_in;
	}
	
};

class OnlineBookReader {
	UserManager usermanagerObj;
	BookManager bookmanagerObj;
  public:
	void addUser(int id, string name, int validity) {
		usermanagerObj.addUser(id, name, validity);
	}
	void addBook(int id, string name, string author) {
		bookmanagerObj.addBook(id, name, author);
	}
	void displayUserManager() { usermanagerObj.displayUserManager(); }
	void displayBookManager() { bookmanagerObj.displayBookManager(); }
	void readABook(int userid, int bookid) {
		if(usermanagerObj.isUserValid(userid)) cout << " User Found" << endl;
		int validity = usermanagerObj.getUserValidity(userid);
		if(validity <= 0) { cout << " This User validity expired" << endl; return ; }
		cout << " Validity = " << usermanagerObj.getUserValidity(userid) << endl;
                if(bookmanagerObj.isBookAvailable(bookid)) cout << " Book Found" << endl;

	}
};
	

int main()  {
	OnlineBookReader onlinebookreaderObj;
	onlinebookreaderObj.addUser(12, "srinivas", 20 );
        onlinebookreaderObj.addUser(13, "amd", 120 );
        onlinebookreaderObj.addUser(14, "nv", 220 );
        onlinebookreaderObj.addUser(12, "srinivas", 20 );
	onlinebookreaderObj.displayUserManager();
//	BookManager onlinebookreaderObj;
	onlinebookreaderObj.addBook(111, "raj", "bb");
        onlinebookreaderObj.addBook(1113, "raj", "bb1");
        onlinebookreaderObj.addBook(1112, "raj", "bb2");
        onlinebookreaderObj.addBook(111, "draj", "bb");
	onlinebookreaderObj.displayBookManager();
	onlinebookreaderObj.readABook(14, 111);
	
}

		
