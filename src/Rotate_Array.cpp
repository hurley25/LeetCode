/*
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4]
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        size_t len = nums.size();
        vector<int> tmps = nums;
        for (int i = 0; i < len; ++i) {
            nums[(i + k) % len] = tmps[i];
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution solution;
    solution.rotate(nums, 3);

    for (auto i : nums) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
