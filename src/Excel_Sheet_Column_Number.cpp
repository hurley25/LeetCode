/*
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number. For example: A -> 1 B -> 2 C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int titleToNumber(string s) {
        int num = 0;
        size_t len = s.size();
        for (size_t i = 0; i < len; ++i) {
            num = num * 26 + s[i] - 'A' + 1;
        }
        return num;
    }
};

int main() {
    Solution solution;

    cout << solution.titleToNumber("A") << endl;
    cout << solution.titleToNumber("Z") << endl;
    cout << solution.titleToNumber("AA") << endl;
    cout << solution.titleToNumber("AB") << endl;

    return 0;
}
