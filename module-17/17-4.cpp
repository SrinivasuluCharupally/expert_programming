// Missing Number: An array A contains all the integers from O to n, except for one number which is missing. In this problem, we cannot access an entire integer in A with a single operation. The elements of A are represented in binary, and the only operation we can use to access them is fetch the jth bit of A[i];' which takes constant time. Write code to find the missing integer. Can you do it in O(n) time


#include<iostream>
#include<vector>
using namespace std;


int MissingNumber(vector<string> arr, int n, int lsb) {
	if(lsb < 0 ) return 0;
	int zeros=0, one=0;
	//for(int k = lsb; k > 0; --k) {
	vector<string> zero_arr, one_arr;
		for(int i = 0; i < n; ++i) {
			if(arr[i].at(lsb) == '0') {
			zero_arr.push_back(arr[i]);
				++zeros;
			}
			else {
                         one_arr.push_back(arr[i]);;
				 ++one;
			}
		}
		if(zeros < one) { 
			int res = MissingNumber(zero_arr, zero_arr.size(), --lsb);
			return (res << 1) | 0;
		}
			
		else {
			int res = MissingNumber(one_arr, one_arr.size(), --lsb);
			return (res << 1) | 1;
		}
	//}

}

int main() {
//	int a[7][3] = { {0,0,0}, {0,0,1}, {0,1,0}, 
//			{0,1,1},          {1,0,1},
//			{1,1,0}, {1,1,1} };
	vector<string> arr ={ "000", "001", "010", "011", "101", "110", "111"};

	int missing = MissingNumber(arr, 7, 2);
	cout << "Missing = " << missing << endl;
}
