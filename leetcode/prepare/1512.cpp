/*
https://leetcode.com/problems/number-of-good-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> prev;
        prev[nums[0]] = 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (prev.find(nums[i]) != prev.end()) {
                ans += prev[nums[i]];
            }
            prev[nums[i]]++;
        }
        return ans;
    }
};
