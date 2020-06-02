// Calculator:Givenanarithmeticequationconsistingofpositiveintegers,+,-,*and/(noparentheses), compute t he result

// source book

#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<double> numStack;
stack<char> optStack;
int pos=0, size=0;


void GetNumOpt(const char* arr) {
	string s;
	if(pos >= size) return;
	if(arr[pos] == '*' || arr[pos] == '+' || arr[pos] == '-' || arr[pos] == '/' ) { 
		optStack.push(arr[pos]); ++pos; return ; }
 	else {
		int digit=1, result=0;
		const char* c = &arr[pos];
                result += atoi(c);

        while(arr[pos] != '*' && arr[pos] != '+' && arr[pos] != '-' && arr[pos] != '/' ) { if(pos >= size) break;
                ++pos;
		
        }
	numStack.push((double)result);
        return;
	}

}

void UpdateResult() {
		double result;
                switch(optStack.top()) {
                        case '*' :
                        result = numStack.top();numStack.pop();
                        result = result * numStack.top();numStack.pop();
                        numStack.push(result);
                        break;
                        case '/' :
                        result = numStack.top();numStack.pop();
                        result = result / numStack.top(); numStack.pop();
                        numStack.push(result);
			break;
                        case '+' :
                        result = numStack.top();numStack.pop();
                        result = result + numStack.top(); numStack.pop();
                        numStack.push(result);
                        break;
                        case '-' :
                        result = numStack.top();numStack.pop();
                        result = result - numStack.top(); numStack.pop();
                        numStack.push(result);
                        break;
	}
	optStack.pop();
}

void Result(char* arr, int size) {
//	if(pos > size) return;
	GetNumOpt(arr);
        if(pos >= size) { UpdateResult(); return; }
	int result;
	if( optStack.top() == '*' || optStack.top() == '/' ) {
		GetNumOpt(arr);
		UpdateResult();
                //GetNumOpt(arr);
		Result(arr, size);
	}
	else {
		char saveLastOpt = optStack.top();
		optStack.pop();	
		UpdateResult();
		optStack.push(savelastopt);
                GetNumOpt(arr);
		Result(arr, size);
	}
//        if(pos >= size) return;
	return;
}			

int FindResult(char* arr, int size) {
		GetNumOpt((const char*)arr);
		GetNumOpt((const char*)arr);
		GetNumOpt((const char*)arr);
		Result(arr, size);
	cout << "Result of given equation is = " << numStack.top() << endl;

}

int main() {
	char arr[] = "2*3+5/6*3+15+1";
	size = (sizeof(arr)/sizeof(arr[0])) -1;
	FindResult(arr, size);
}
