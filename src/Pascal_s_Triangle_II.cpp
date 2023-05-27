/*
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 *    For example, given k = 3,
 *    Return [1,3,3,1].
 *
 *    Note:
 *       Could you optimize your algorithm to use only O(k) extra space?
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getrow(int rowIndex) {
        vector<int> rowVect;
        for (int i = 0; i < rowIndex; i++) {
            if (i == 0) {
                rowVect.push_back(1);
            } else {
                rowVect.push_back(0);
            }
        }

        for (int i = 0; i < rowIndex; i++) {
            for (int j = i + 1; j > 0; j--) {
                rowVect[j] += rowVect[j - 1];
            }
        }
        rowVect.push_back(1);

        return rowVect;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    int level = 3;
    if (argc == 2) {
        level = atoi(argv[1]);
    }

    vector<int> rowVect = solution.getrow(level);

    std::cout << "[";
    for (size_t i = 0; i < rowVect.size(); ++i) {
        std::cout << rowVect[i];
        if (i + 1 != rowVect.size()) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
