// boolean parenthesis , (0^1)|(1&0)
//source book, but not working


#include<iostream>
#include<string>
using namespace std;

bool stringToBool(string c) {
	if(c == "1") return true;
	else return false;
}

int countEval(string s, bool result) {
	if(s.length() == 0) return 0;
	if(s.length() == 1) { return stringToBool(s) == result?1:0; }
	int ways = 0;
	for(int i = 1; i < s.length(); i +=2) {
		char c = s.at(i);
		string left = s.substr(0,i);
		string right = s.substr(i+1, s.length());
		int leftTrue = countEval(left,true);
		int leftFalse = countEval(left,false);
		int rightTrue = countEval(right,true);
		int rightFalse = countEval(right,false);
		int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);
		int totalTrue = 0;
		if(c == '^')
			totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
		else { if(c == '&') 
			totalTrue = leftTrue * rightTrue;
			else if(c == '|')
				totalTrue = leftTrue*rightTrue + leftFalse*rightTrue + leftTrue*rightFalse;
		}

		int subWays = result ? totalTrue: total-totalTrue;
		ways += subWays;
	}
	return ways;
}

int main() {
	string s = "1&0|1|0";
	bool result;
	int ways = countEval(s,result);
	cout << "total ways" << ways<< endl;
}
