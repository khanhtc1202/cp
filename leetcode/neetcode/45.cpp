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
};
