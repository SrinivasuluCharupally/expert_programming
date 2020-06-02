// printing last K lines from a given file
// in this example i use char array instead file...

// it uses circular array,
// source book


#include<iostream>
using namespace std;

int main() {
	char c[] = "abcdefghijkl";
	char output[4];

	int size = sizeof(c)/sizeof(c[0]);
	int counter = 0;
	for(int i =0; i < size-1; ++i) { // here we read line by line until EOF
		if(counter ==4) counter = 0;

			output[counter] = c[i];
			counter++;
	}

	for(int i = counter ; i < 4; ++i)
		cout << output[i] << endl;

	for(int i = 0; i < counter; ++i)
		cout << output[i] << endl;
}


