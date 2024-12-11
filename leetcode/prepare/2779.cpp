/*
https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int r = 0, ans = 0;
        int cond = 2*k;
        for (int l = 0; l < nums.size(); ++l) {
            while (r < nums.size() && nums[r] - nums[l] <= cond) {
                r++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }

    int maximumBeaty_Opt(vector<int>& nums, int k) {
        if (nums.size() == 1) return 1;

        int maxBeauty = INT_MIN;
        int maxValue = INT_MIN;

        for (auto x: nums) maxValue = max(maxValue, x);

        vector<int> count(maxValue+1, 0);
        for (auto x: nums) {
            count[max(x - k, 0)]++; // add 1 to the start of the range
            if (x+k+1 <= maxValue) count[x+k+1]--; // subtract 1 to the end of the range
        }

        int currSum = 0; // represents the current overlaped ranges
        for (auto val: count) {
            currSum += val;
            maxBeauty = max(maxBeauty, currSum);
        }
        return maxBeauty;
    }
};
