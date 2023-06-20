/*
https://leetcode.com/problems/missing-ranges/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (lower < nums[i]) {
                ans.push_back({lower, nums[i]-1});
            }
            lower = nums[i]+1;
        }
        if (lower <= upper) {
            ans.push_back({lower, upper});
        }
        return ans;
    }
};
