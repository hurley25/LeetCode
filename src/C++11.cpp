#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> str = {"1", "2", "3", "4", "5"};
    sort(str.begin(), str.end(), [](string &a, string &b) { return a < b; });
    for_each(str.begin(), str.end(),
             [](const string str) { cout << str << endl; });

    return 0;
}
