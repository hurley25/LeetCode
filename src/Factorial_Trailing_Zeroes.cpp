/*
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            n /= 5;
            res += n;
        }
        return res;
    }
};

int main() {
    Solution solution;

    return 0;
}
