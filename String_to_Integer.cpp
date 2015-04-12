/*
* Implement atoi to convert a string to an integer.
* Hint: Carefully consider all possible input cases.
* If you want a challenge, please do not see below and ask yourself what are the possible input cases.
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
* You are responsible to gather all the input requirements up front.
*/

#include <iostream>
#include <cstdint>
#include <cctype>

using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		bool sign = false;
		int64_t num = 0;

		while (*str && isspace(*str)) {
			str++;
		}
		if (*str == '-') {
			sign = true;
			str++;
		} else if (*str == '+') {
			str++;
		}
		while (*str) {
			if (isdigit(*str)) {
				num = num * 10 + (*str - '0');
				str++;
				if (sign && -num <= INT_MIN) {
					return INT_MIN;
				} else if (!sign && num >= INT_MAX) {
					return INT_MAX;
				}
			} else {
				break;
			}
		}
		num = sign ? -num : num;
	
		return (int)num;
	}
};

int main(int argc, char *argv[])
{
	Solution solution;

	cout << solution.atoi(" -12345611111111") << endl;
	cout << solution.atoi(" -1234 ") << endl;
	cout << solution.atoi("  1234") << endl;
	cout << solution.atoi(" +-2 ") << endl;
	cout << solution.atoi("  -0012a42") << endl;
	cout << solution.atoi(" b11228552307") << endl;
	cout << solution.atoi("9223372036854775809") << endl;
	cout << solution.atoi("-2147483648") << endl;
	cout << solution.atoi("-2147483647") << endl;
	
	return 0;
}
