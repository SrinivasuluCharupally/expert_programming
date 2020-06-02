// Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

//. optimized, no need to compute pertucular iteration every time.
// save the result in array then use it

#include<iostream>

using namespace std;
int TripleStep(int, int[]);

int main() {
	int n = 3;
	int array[4] = { -1, -1, -1, -1};
	int result = TripleStep(n, array);
	cout << " Total count = " << result << endl;
}

int TripleStep(int n, int array[]) {
	if(n < 0) return 0;
	if(n == 0) return 1;
	else if(array[n] > -1) return array[n];
	else {
		array[n] = TripleStep(n-1, array) + TripleStep(n-2, array) + TripleStep(n-3, array);
		return array[n];
	}
//	return array[n];

}
