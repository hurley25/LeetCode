/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> romanMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
										{'C', 100}, {'D', 500}, {'M', 1000}};
		int sum = romanMap[s.back()];
		for (int i = s.length() - 2; i >= 0; --i) {
			if (romanMap[s[i]] < romanMap[s[i + 1]]) {
				sum -= romanMap[s[i]];
			} else {
				sum += romanMap[s[i]];
			}
		}

		return sum;
	}
};

int main(int argc, char *argv[])
{
	Solution solution;

	cout << solution.romanToInt("VI") << endl;
	return 0;
}