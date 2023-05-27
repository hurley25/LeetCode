/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 */

#include <iostream>

using namespace std;

class Solution {
  public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }

        int count1 = 1, count2 = 2, count3 = 0;
        for (int i = 3; i <= n; ++i) {
            count3 = count1 + count2;
            count1 = count2;
            count2 = count3;
        }

        return count3;
    }
};

int main() {
    Solution solution;

    cout << solution.climbStairs(0) << endl;
    cout << solution.climbStairs(1) << endl;
    cout << solution.climbStairs(2) << endl;
    cout << solution.climbStairs(3) << endl;
    cout << solution.climbStairs(4) << endl;
    cout << solution.climbStairs(5) << endl;

    return 0;
}
