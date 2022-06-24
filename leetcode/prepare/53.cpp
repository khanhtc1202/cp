#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int maxSum = nums[0];
        int curSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (curSum < 0)
                curSum = 0;
            
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }

    int maxSubArray1(vector<int>& nums) {
        int sum = 0, mn = 0;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum - mn);
            mn = min(mn, sum);
        }
        return ans;
    }
};
