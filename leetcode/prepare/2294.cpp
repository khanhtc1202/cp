/*
https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, curr_min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - curr_min > k) {
                ans++;
                curr_min = nums[i];
            }
        }
        return ans;
    }
};
