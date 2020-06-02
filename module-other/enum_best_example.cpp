#include<iostream>
#include<string>

using namespace std;

enum Status { HSA_SUCESS, HSA_FAIL, HSA_ERROR };
const string StatusArray[3] = { "HSA_SUCESS", "HSA_FAIL", "HSA_ERROR" };
int main() {
	Status status_;
	status_ = HSA_FAIL;
	cout << status_ << endl;
	if(status_ == HSA_SUCESS)  cout << " good" << endl;
	else cout << "bad" << endl;
	
        if(status_ == 1)  cout << " good" << endl;
        else cout << "bad" << endl;
	status_ = (Status)2;
	cout << "String at 2 = " << StatusArray[status_] << endl;
}
