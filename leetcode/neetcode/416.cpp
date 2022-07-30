#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums)
            sum += n;

        int sub = sum / 2;
        if (sum != sub*2)
            return false;

        vector<int> dp(sub+1, false);
        dp[0] = true;
        for (auto num: nums)
            for (int i = sub; i >= num; i--)
                dp[i] = dp[i] || dp[i-num];
        return dp[sub];
    }

    bool canPartitionSet(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums)
            sum += n;

        int sub = sum /2;
        if (sum != sub*2)
            return false;

        unordered_set<int> sums;
        sums.insert(0);
        for (auto num: nums) {
            unordered_set<int> tmp;
            for (auto sum: sums) {
                if (sum+num == sub)
                    return true;
                tmp.insert(sum+num);
                tmp.insert(sum);
            }                
            sums = tmp;
        }            
        return false;
    }

    bool canPartitionBottomUp(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums)
            sum += n;

        int sub = sum /2;
        if (sum != sub*2)
            return false;

        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sub+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            int num = nums[i-1];
            for (int j = 0; j <= sub; j++) {
                if (num > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-num];
            }
        }
        return dp[nums.size()][sub];
    }
};
