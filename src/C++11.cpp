#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> str = {0, 0, 0, 0, 0};
	sort(str.begin(), str.end(), [] (string &a, string &b) {return a < b; });
	for_each(str.begin(), str.end(),  [] (const string str) {cout << str << endl;});

	return 0;
}