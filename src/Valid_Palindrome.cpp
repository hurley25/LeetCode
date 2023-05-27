/*
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases. For example, "A man, a plan, a
 * canal: Panama" is a palindrome. "race a car" is not a palindrome.
 *
 *    Note:
 *       Have you consider that the string might be empty?
 *       This is a good question to ask during an interview.
 *       For the purpose of this problem, we define empty string as valid
 * palindrome.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        string::iterator begin = s.begin();
        string::iterator end = s.end() - 1;

        while (begin < end) {
            while (begin < end && !isalnum(*begin)) {
                ++begin;
            }
            while (begin < end && !isalnum(*end)) {
                --end;
            }
            if (tolower(*begin) != tolower(*end)) {
                return false;
            }
            ++begin;
            --end;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    std::cout << solution.isPalindrome("A man, a plan, a canal: Panama")
              << std::endl;

    return 0;
}
