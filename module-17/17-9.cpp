// Kth Multiple: Design an algorithm to  find the kth number such that the only prime factors are 3, 5, and 7. Note that 3, 5, and 7 do not have to be factors, but it should not have any other prime factors. For example, the first several multiples would be (in order) 1, 3, 5, 7, 9, 15, 21.


// source book & https://hellosmallworld123.wordpress.com/2014/05/14/find-the-kth-number-with-only-prime-factors-of-3-5-and-7/


#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> queue3, queue5, queue7;
	int k = 10, min=0;
	queue3.push(3); queue5.push(5); queue7.push(7);
	for(int i = 0; i < k; ++i) {
		int v3 = queue3.front();
		int v5 = queue5.front();
		int v7 = queue7.front();
		min = v7 < (v3 < v5 ? v3 : v5) ? v7 : (v3 < v5 ? v3 : v5);

		if(min == v3) {
			queue3.pop();
			queue3.push(min*3);
			queue5.push(min*5);
		}
		else { 
			if(min == v5) {
				queue5.pop();
				queue5.push(min*5);
			}
			else if(min == v7) {
				queue7.pop();
			}
		}

		queue7.push(min*7);
	}
	cout << min << endl; // min the 10th number in the sequence which is factor of either 3, or 5, or 7...
// sequence is : 3, 5, 7, 9, 15, 21, 25, 27, 35 , 45 ...
}
