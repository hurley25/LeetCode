/*
 * Given a sorted array, remove the duplicates in place such that
 * each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory. For example, Given input array A = [1,1,2], Your function
 * should return length = 2, and A is now [1,2].
 */

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        int j = 1;
        while (i < n - 1) {
            while (A[i] == A[j]) {
                ++j;
                if (j == n) {
                    return i + 1;
                }
            }
            A[++i] = A[j];
        }
        return n;
    }
};

#define LENGTH 5

int main() {
    int array[LENGTH] = {0, 0, 0, 0, 0};

    Solution solution;
    int count = solution.removeDuplicates(array, LENGTH);
    cout << "Count: " << count << endl;

    for_each(array, array + count, [](int n) { cout << n << " "; });
    cout << endl;

    return 0;
}
