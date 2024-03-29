/*
 * Compare two version numbers version1 and version1.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise
 * return 0. You may assume that the version strings are non-empty and contain
 * only digits and the . character. The . character does not represent a decimal
 * point and is used to separate number sequences. For instance, 2.5 is not "two
 * and a half" or "half way to version three", it is the fifth second-level
 * revision of the second first-level revision. Here is an example of version
 * numbers ordering: 0.1 < 1.1 < 1.2 < 13.37
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int compareVersion(string version1, string version2) {
        size_t pos1, pos2;
        int v1, v2;
        while (!(version1.empty() && version2.empty())) {
            pos1 = version1.find(".");
            pos2 = version2.find(".");
            if (pos1 != string::npos) {
                v1 = stoi(version1.substr(0, pos1));
                version1.erase(0, pos1 + 1);
            } else if (!version1.empty()) {
                v1 = stoi(version1);
                version1.clear();
            } else {
                v1 = 0;
            }
            if (pos2 != string::npos) {
                v2 = stoi(version2.substr(0, pos2));
                version2.erase(0, pos2 + 1);
            } else if (!version2.empty()) {
                v2 = stoi(version2);
                version2.clear();
            } else {
                v2 = 0;
            }
            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;

    cout << solution.compareVersion("1.9.9.9", "1.10.0.0") << endl;
    cout << solution.compareVersion("1.2", "1.37") << endl;
    cout << solution.compareVersion("1.2.3", "1.2.4") << endl;
    cout << solution.compareVersion("1.2.3", "1.2") << endl;
    cout << solution.compareVersion("1.2.3", "1.2.3") << endl;
    cout << solution.compareVersion("1.01", "1") << endl;

    return 0;
}
