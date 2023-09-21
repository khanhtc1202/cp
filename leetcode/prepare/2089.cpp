/*
https://leetcode.com/problems/find-target-indices-after-sorting-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> ans;
        while (start < end) {
            ans.push_back(start++);
        }
        return ans;
    }
};
