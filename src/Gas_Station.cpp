/*
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i]. You have a car with an unlimited gas tank and it costs
 * cost[i] of gas to travel from station i to its next station (i+1). You begin
 * the journey with an empty tank at one of the gas stations. Return the
 * starting gas station's index if you can travel around the circuit once,
 * otherwise return -1.
 * Note:
 * The solution is guaranteed to be unique.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) {
            return -1;
        }
        int total = 0, sum = 0, startIdx = 0;
        for (size_t i = 0; i < gas.size(); ++i) {
            int remain = gas[i] - cost[i];
            total += remain;
            if (sum >= 0) {
                sum += remain;
            } else {
                sum = remain;
                startIdx = i;
            }
        }
        return total >= 0 ? startIdx : -1;
    }
};

int main() {
    Solution solution;

    return 0;
}
