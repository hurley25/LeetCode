/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 *   For example, given numRows = 5,
 *   Return
 *   [
 *        [1],
 *       [1,1],
 *      [1,2,1],
 *     [1,3,3,1],
 *    [1,4,6,4,1]
 *   ]
 */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
        vector<vector<int> > generate(int numRows) {
                vector<vector<int> > pascalVect;
                vector<int> rowVect;

                if (numRows == 0) {
                        return pascalVect;
                }
        
                // 此处有意循环展开，避免每次循环都进行分支预测
                rowVect.push_back(1);
                pascalVect.push_back(rowVect);
                if (numRows == 1) {
                        return pascalVect;
                }

                for (int i = 1; i < numRows; ++i) {
                        rowVect.clear();
                        rowVect.push_back(1);
                        for (int j = 1; j < i; ++j) {
                                rowVect.push_back(pascalVect[i-1][j] + pascalVect[i-1][j-1]);       
                        }
                        rowVect.push_back(1);
                        pascalVect.push_back(rowVect);
                }

                return pascalVect;
        }
};

int main(int argc, char *argv[])
{
        Solution solution;

        int level = 0;
        if (argc == 2) {
                level = atoi(argv[1]);
        }

        vector<vector<int> > pascalVect = solution.generate(level);

        std::cout << "[" << std::endl;
        int blank = level;
        for (size_t i = 0; i < pascalVect.size(); ++i) {
                for (int k = blank; k > 0; --k) {
                        std::cout << " ";
                }
                blank--;
                std::cout << "[";
                for (size_t j = 0; j < pascalVect[i].size(); ++j) {
                        std::cout << pascalVect[i][j];
                        if (j + 1 != pascalVect[i].size()) {
                                std::cout << ",";
                        }
                }
                std::cout << "]";
                if (i + 1 != pascalVect.size()) {
                        std::cout << ",";
                }
                std::cout << std::endl;
        }
        std::cout << "]" << std::endl;

        return 0;
}
