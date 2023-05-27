/*
 * Given a positive integer, return its corresponding column title as appear in
 *an Excel sheet.
 *
 * For example:
 *
 *		1 -> A
 *		2 -> B
 *		3 -> C
 *		...
 *		26 -> Z
 *		27 -> AA
 *		28 -> AB
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string convertToTitle(int n) {
        string result = "";
        while (n > 0) {
            int mod = n % 26;
            n -= mod;
            if (mod == 0) {
                result = 'Z' + result;
                n -= 26;
                n /= 26;
            } else {
                char ch = 'A' + mod - 1;
                result = ch + result;
                n /= 26;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    cout << solution.convertToTitle(1) << endl;
    cout << solution.convertToTitle(26) << endl;
    cout << solution.convertToTitle(27) << endl;
    cout << solution.convertToTitle(28) << endl;

    return 0;
}
