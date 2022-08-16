#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, add = 0;
        int total_tank = 0, curr_tank = 0;
        for (int i = 0; i < n; i++) {
            add = gas[i] - cost[i];
            total_tank += add;

            curr_tank += add;
            // if the current tank is < 0 mean it's impossible to reach this station
            // with any of previous starting point, then the stating point should be
            // after this point, means reset start to i+1 and reset counting tank to 0.
            if (curr_tank < 0) {
                curr_tank = 0;
                start = i+1;
            }
        }
        if (total_tank < 0) return -1;
        return start == n ? 0 : start;
    }
};
