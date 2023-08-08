/*
https://leetcode.com/problems/two-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        hm[nums[0]] = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (hm.find(target - nums[i]) != hm.end()) {
                return {hm[target-nums[i]], i};
            }
            hm[nums[i]] = i;
        }
        return {};
    }
};
