/*
 * Given an array and a value, remove all instances of that value in place and
 * return the new length. The order of elements can be changed. It doesn't
 * matter what you leave beyond the new length.
 */

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        while (i < n) {
            if (A[i] == elem) {
                while (A[n - 1] == elem) {
                    n--;
                }
                if (i < n) {
                    A[i] = A[n - 1];
                    n--;
                }
            }
            i++;
        }

        return n;
    }
};

#define LENGTH 5

int main() {
    int array[LENGTH] = {1, 3, 2, 3, 5};

    Solution solution;
    int count = solution.removeElement(array, LENGTH, 3);

    for_each(array, array + count, [](int n) { cout << n << " "; });
    cout << endl;

    return 0;
}
