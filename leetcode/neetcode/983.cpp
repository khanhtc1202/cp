#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int sz = days[days.size()-1];
        vector<int> dp(sz+1, 0);
        dp[days[0]] = *min_element(costs.begin(), costs.end());
        for (int i = 1; i < days.size(); i++) {
            int date = days[i];
            int c1 = costs[0] + dp[days[i-1]];

            int c2 = costs[1];
            for (int j = date - 7; j > 0; j--) {
                if (dp[j] > 0) {
                    c2 += dp[j];
                    break;
                }
            }

            int c3 = costs[2];
            for (int j = date - 30; j > 0; j--) {
                if (dp[j] > 0) {
                    c3 += dp[j];
                    break;
                }
            }
            
            dp[date] = min(min(c1, c2), c3);
        }
        return dp[sz];
    }
};
