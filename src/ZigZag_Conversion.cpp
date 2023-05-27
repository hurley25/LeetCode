/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern
 * on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a
 number of rows:

 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  private:
    int down(int nRows, int row) { return 2 * (nRows - row - 1); }

    int up(int row) { return 2 * row; }

    int step(int nRows, int row, bool is_down) {
        if (nRows == 1)
            return 1;
        if (row == 0 || row == nRows - 1)
            return 2 * (nRows - 1);
        return is_down ? down(nRows, row) : up(row);
    }

  public:
    string convert(string s, int nRows) {
        string result(s.size(), '\n');
        int cur_index = 0;
        for (int row = 0; row < nRows; ++row) {
            bool is_down = true;
            for (size_t i = row; i < s.size();
                 i += step(nRows, row, is_down), is_down = !is_down) {
                result[cur_index++] = s[i];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    return 0;
}
