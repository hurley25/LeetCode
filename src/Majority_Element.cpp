/*
 * Given an array of size n, find the majority element. 
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int> &num) {
		int vote = num[0];
		int count = 1;
		for (size_t i = 1; i < num.size(); i++) {
			if (count == 0) {
				vote = num[i];
				count = 1; 
			} else if (vote == num[i]) {
				count++;
			} else {
				count--;
			}
		}
		return vote;
	}
};

int main()
{
	vector<int> num = {1, 5, 2, 6, 4, 1, 1, 1, 1, 1};
	Solution solution;
	cout << solution.majorityElement(num) << endl;

	return 0;
}
