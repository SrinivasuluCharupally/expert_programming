//Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print"ERROR "

#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
    double d = 0.72;
    string result = "0.";
    while(d != 0 && result.size() != 32) {
        d = d * 2;
        if(d >= 1) { result += "1"; d -= 1; }
        else { result += "0"; }
        
    }
	cout << " binary format is = " << result << endl;
	return 0;
}
