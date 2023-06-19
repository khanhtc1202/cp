/*
https://leetcode.com/problems/degree-of-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> count, left, right;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if (left.find(nums[i]) == left.end()) left[nums[i]] = i;
            right[nums[i]] = i;
        }

        int degree = 0;
        for (auto kv: count) {
            degree = max(degree, kv.second);
        }

        int ans = nums.size();
        for (auto kv: count) {
            int num = kv.first, d = kv.second;
            if (d < degree) continue;

            ans = min(ans, right[num] - left[num] + 1);
        }
        return ans;
    }
};
