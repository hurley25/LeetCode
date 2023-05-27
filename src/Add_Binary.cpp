/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 *	 a = "11"
 *	 b = "1"
 *	 Return "100".
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) {
            b = (string(a.size() - b.size(), '0') + b);
        } else if (a.size() < b.size()) {
            a = (string(b.size() - a.size(), '0') + a);
        }
        string res = "";
        int carry = 0;
        int digit = 0;
        while (a != "" && b != "") {
            int a_digit = static_cast<int>(a.back() - '0');
            int b_digit = static_cast<int>(b.back() - '0');
            digit = (a_digit + b_digit + carry) % 2;
            carry = (a_digit + b_digit + carry) / 2;
            res = (std::to_string(digit) + res);
            a.pop_back();
            b.pop_back();
        }
        if (carry == 1) {
            res = (to_string(carry) + res);
        }

        return res;
    }
};

int main() {
    string a = "1011010";
    string b = "1011001";

    Solution solution;
    cout << solution.addBinary(a, b) << endl;

    return 0;
}
