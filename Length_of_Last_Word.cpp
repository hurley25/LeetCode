/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example,
 *   Given s = "Hello World",
 *   return 5.
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (!s || !s[0]) {
			return 0;
		}
		int size = strlen(s);
		int i = size-1;
		while (i >= 0 && s[i] == ' ') {
			--i;
			--size;
		}
		while (i >= 0 && s[i] != ' ') {
			--i;
		}

		return size - i - 1;
	}
};

int main()
{
	Solution solution;

	cout << solution.lengthOfLastWord("Hello World") << endl;
	cout << solution.lengthOfLastWord(" World") << endl;
	cout << solution.lengthOfLastWord("HelloWorld") << endl;
	cout << solution.lengthOfLastWord("a ") << endl;
	cout << solution.lengthOfLastWord("") << endl;

	return 0;
}
