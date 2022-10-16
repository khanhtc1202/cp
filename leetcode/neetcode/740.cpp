#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> points;
        int maxPoint = 0;
        for (auto num: nums) {
            points[num] += num;
            maxPoint = max(maxPoint, num);
        }
        
        vector<int> dp(maxPoint+1, 0);
        dp[1] = points[1];
        for (int i = 2; i <= maxPoint; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + points[i]);
        }
        return dp[maxPoint];
    }
};
