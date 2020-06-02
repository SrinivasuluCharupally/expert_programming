// Parens: Implement an algorithm to print all valid (i.e., properly opened and closed) combinations of n pairs of parenthese

// see this diagram for better understanding http://algorithms.tutorialhorizon.com/generate-all-valid-parenthesis-strings-of-length-2n-of-given-n/



#include<iostream>
#include<list>

using namespace std;

void PrintParens(list<string>*, int, int, char*, int);


void PrintParens(list<string>* listParens, int leftmem, int rightmem, char* str, int index) {

    if(leftmem < 0 || leftmem > rightmem) return;
    if(leftmem== 0 && rightmem == 0) {
        listParens->push_back(str);
    }
    else {
        str[index] = '(';
        PrintParens(listParens, leftmem-1, rightmem, str, index+1);
//                str[index] = '(';

        str[index] = ')';
        PrintParens(listParens, leftmem, rightmem-1, str, index+1);
//                str[index] = ')';

    }
}


int main() {
	int count = 2;
	char* str = new char[count*2];
	list<string>* listParens = new list<string>;
	PrintParens(listParens, count, count, str, 0);
	for(list<string>::iterator itr = listParens->begin(); itr != listParens->end(); ++itr) {
		cout << *itr << endl;
	}

}

