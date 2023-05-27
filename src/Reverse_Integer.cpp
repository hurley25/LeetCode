/*
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * For the purpose of this problem, assume that your function returns 0 when the
 * reversed integer overflows.
 */

#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
  public:
    int reverse(int x) {
        int64_t num = 0;

        while (x != 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        if (num > INT_MAX || num < INT_MIN) {
            return 0;
        }

        return (int)num;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.reverse(-123) << endl;
    return 0;
}
