#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e4);
        dp[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            int steps = min(n-1-i, nums[i]);
            for (int j = 1; j <= steps; j++) {
                dp[i] = min(dp[i], 1+dp[i+j]);
            }
        }
        return dp[0];
    }

    int jumpGreedy(vector<int>& nums) {
        int n = nums.size();
        int jump = 0;
        int fastest = 0, end_slide = 0;
        for (int i = 0; i < n-1; i++) {
            fastest = max(fastest, i + nums[i]);
            if (i == end_slide) {
                jump++;
                end_slide = fastest;
            }
        }
        return jump;
    }

    int jumpBFSOpt(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int jump = 0;
        while (r < n-1) {
            int sz = 0;
            for (int i = l; i <= r; i++) {
                sz = max(sz, i + nums[i]);
            }
            l = r+1;
            r = sz;
            jump++;
        }
        return jump;
    }
};
