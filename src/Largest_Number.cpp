/*
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * Note: The result may be very large, so you need to return a string instead of an integer.
 * Credits:
 *     Special thanks to @ts for adding this problem and creating all test cases.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int> &num) {
		vector<string> numStrVect;
		for (size_t i = 0; i < num.size(); ++i) {
			numStrVect.push_back(to_string(num[i]));
		}
		sort(numStrVect.begin(), numStrVect.end(),
			[](const string &str1, const string &str2) {
				return str2 + str1 < str1 + str2;
			});
		string result;
		for (size_t i = 0; i < numStrVect.size(); ++i) {
			result += numStrVect[i];
		}
		if (result[0] == '0') {
			return string("0");
		}
		return result;
	}
};

int main()
{
	vector<int> num1 = {3, 30, 34, 5, 9};
	vector<int> num2 = {0, 0, 0, 0, 0};

 	Solution solution;
 	cout << solution.largestNumber(num1) << endl;
 	cout << solution.largestNumber(num2) << endl;

	return 0; 
}
