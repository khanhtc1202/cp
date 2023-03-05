/*
Problem desc: https://leetcode.com/problems/predict-the-winner/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n, 0);
        presum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            presum[i] = presum[i-1] + nums[i];
        }

        auto sum_range = [&](int l, int r) -> int {
            if (l > r) return 0;
            return presum[r] - presum[l] + nums[l];
        };

        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> play = [&](int l, int r) -> int {
            if (l > r) return 0;
            if (dp[l][r] != -1) return dp[l][r];

            int choose_left = nums[l] + sum_range(l+1, r) - play(l+1, r);
            int choose_right = nums[r] + sum_range(l, r-1) - play(l, r-1);

            return dp[l][r] = max(choose_left, choose_right);
        };

        int first = play(0, n-1);
        int second = sum_range(0, n-1) - first;
        return first >= second;
    }
};
