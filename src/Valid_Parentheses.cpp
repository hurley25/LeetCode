/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * The brackets must close in the correct order, 
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> chstack;
		string::const_iterator idx = s.cbegin();
		while (idx != s.cend()) {
			if (*idx == '(' || *idx == '[' || *idx == '{') {
				chstack.push(*idx);
			} else {
				if (!chstack.empty()) {
					char ch = chstack.top();
					if (*idx == ']' && ch != '[') {
						return false;
					}
					if (*idx == ')' && ch != '(') {
						return false;
					}
					if (*idx == '}' && ch != '{') {
						return false;
					}
					chstack.pop();
				} else {
					return false;
				}
			}
			++idx;
		}

		if (chstack.empty()) {
			return true;
		}

		return false;
	}
};

int main()
{
	Solution solution;

	cout << solution.isValid("") << endl;
	cout << solution.isValid("{}") << endl;
	cout << solution.isValid("()[]{}") << endl;
	cout << solution.isValid("{]") << endl;
	cout << solution.isValid("([)]") << endl;
	cout << solution.isValid("()[]{") << endl;

	return 0;
}
