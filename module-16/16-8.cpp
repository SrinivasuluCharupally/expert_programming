// English Int: Given any integer, print an English phrase that describes the integer (e.g., "One Thousand, Two Hundred Thirty Four")

// source book

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string string_single[] = {"one", "two", "three", "four", "five", "sixe", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fouteen", "fifteen", "sxteen", "seventeen", "eighteen", "ninteen"};

string string_tens[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};

string string_big[] = {"hundred", "thousend", "milion" };

stack<string> storage;

void converter(int n, int p) {
if(p == 0) {
	if(n%100 < 20) {
		storage.push(string_single[n%100 - 1]); n = n/100;
	}
	else {
		storage.push(string_single[n%10 - 1]); n = n/10;
		storage.push(string_tens[n%10 - 2]); n = n/10;
	}
	storage.push(string_big[n%10 - 1]);
	if(n !=0 ) 
	storage.push(string_single[n%10 - 1]); 
}
else {
        storage.push(string_big[p]);

        if(n%100 < 20) {
                storage.push(string_single[n%100 - 1]); n = n/100;
        }
        else {
                storage.push(string_single[n%10 - 1]); n = n/10;
                storage.push(string_tens[n%10 - 2]); n = n/10;
        }
	if(n ==0) return;
        storage.push(string_big[n%10 - 1]);
        if(n !=0 )
        storage.push(string_single[n%10 - 1]);

}	
}

int main() {
	int number;
	//stack<string> storage;
	cout << "Enter number " ; cin >> number;
	for(int i = 1000, position = 0; number > 0; i *= 1000, position++) {
		converter(number % i, position) ;
		number /= 1000;
	}
	while(!storage.empty()){
		cout << storage.top() << " " ;
		storage.pop();
	}
		
	cout << endl;
}

	
