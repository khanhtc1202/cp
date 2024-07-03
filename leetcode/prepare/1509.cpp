/*
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, N = nums.size();
        for (int i = 0; i <= 3; ++i) {
            ans = min(ans, nums[N-1-i] - nums[3-i]);
        }
        return ans;
    }
};
