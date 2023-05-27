/*
 * Given a non-negative number represented as an array of digits, plus one to
 * the number. The digits are stored such that the most significant digit is at
 * the head of the list.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size() - 1;
        while (digits[n] == 9 && n > 0) {
            digits[n] = 0;
            n--;
        }
        if (n == 0 && digits[n] == 9) {
            digits[n] = 0;
            digits.insert(digits.begin(), 1);
        } else {
            digits[n]++;
        }

        return digits;
    }
};

int main() {
    vector<int> num1 = {1, 1, 1, 1, 1};
    vector<int> num2 = {1, 1, 1, 1, 9};
    vector<int> num3 = {1, 1, 1, 9, 9};
    vector<int> num4 = {9, 9, 9, 9, 9};

    Solution solution;
    solution.plusOne(num1);
    for_each(num1.begin(), num1.end(), [](int n) { cout << n; });
    cout << endl;
    solution.plusOne(num2);
    for_each(num2.begin(), num2.end(), [](int n) { cout << n; });
    cout << endl;
    solution.plusOne(num3);
    for_each(num3.begin(), num3.end(), [](int n) { cout << n; });
    cout << endl;
    solution.plusOne(num4);
    for_each(num4.begin(), num4.end(), [](int n) { cout << n; });
    cout << endl;

    return 0;
}
