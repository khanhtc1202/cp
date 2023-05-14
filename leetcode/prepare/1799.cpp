/*
https://leetcode.com/problems/maximize-score-after-n-operations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1<<n, 0);
        vector<vector<int>> _gcd(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                _gcd[i][j] = gcd(nums[i], nums[j]);
            }
                
        
        for (int mask = 0; mask < 1<<n; mask++) {
            int sz = 0;
            for (int i = 0; i < n; i++) sz += (mask >> i & 1);
            if (sz&1) continue;
            
            int idx = sz/2 + 1;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) continue;
                
                for (int j = i+1; j < n; j++) {
                    if (mask >> j & 1) continue;
                    
                    int nxt = (mask ^ (1<<i) ^ (1<<j));
                    dp[nxt] = max(dp[nxt], dp[mask] + idx * _gcd[i][j]);
                }
            }
        }
        return dp[(1<<n) - 1];
    }
};
