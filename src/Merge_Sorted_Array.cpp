/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * 
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) 
 * to hold additional elements from B. 
 * The number of elements initialized in A and B are m and n respectively.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m - 1;
		int j = n - 1;
		while (j >= 0) {
			while (i >= 0 && A[i] >= B[j]) {
				A[i+j+1] = A[i];
				--i;
			}
			A[i+j+1] = B[j];
			--j;
		}
	}
};

int main()
{	
	int a[10] = {1, 2, 5, 7};
	int b[] = {3, 6, 6, 7, 8, 9};

	Solution solution;
	solution.merge(a, 4, b, 6);

	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
