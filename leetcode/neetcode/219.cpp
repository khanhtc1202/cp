/*
Problem: https://leetcode.com/problems/contains-duplicate-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) return true;
            seen.insert(nums[i]);
            if (seen.size() > k) seen.erase(nums[i-k]);
        }
        return false;
    }
};
