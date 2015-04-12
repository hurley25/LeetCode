/*
* Determine whether an integer is a palindrome.Do this without extra space.
*/

#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		if (x < 10) {
			return true;
		}
		int reverse = 0;
		int orgin = x;
		while (orgin != 0) {
			reverse = reverse * 10 + orgin % 10;
			orgin /= 10;
		}

		return (reverse == x);
	}
};

int main(int argc, char *argv[])
{
	Solution solution;

	cout << solution.isPalindrome(2147483647) << endl;
	cout << solution.isPalindrome(12321) << endl;
	cout << solution.isPalindrome(11) << endl;

	return 0;
}
