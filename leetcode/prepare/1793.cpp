/*
https://leetcode.com/problems/maximum-score-of-a-good-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int _min = nums[k], i = k, j = k, ans = INT_MIN;
        while (i > 0 || j < n-1) {
            if (i == 0) j++;
            else if (j == n-1) i--;
            else if (nums[i-1] < nums[j+1]) j++;
            else i--;
            _min = min({_min, nums[i], nums[j]});
            ans = max(ans, _min * (j-i+1));
        }
        return ans;
    }
};
