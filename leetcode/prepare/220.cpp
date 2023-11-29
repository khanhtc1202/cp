/*
https://leetcode.com/problems/contains-duplicate-iii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int iDiff, int vDiff) {
        unordered_map<int, int> bucket;
        int _vDiff = max(vDiff, 1); // Use vDiff = 1 instead if vDiff = 0

        for (int i = 0; i < nums.size(); ++i) {
            int bIdx = nums[i] / _vDiff;

            if (bucket.find(bIdx) != bucket.end() && abs(nums[i] - bucket[bIdx]) <= vDiff)
                return true;

            if (bucket.find(bIdx - 1) != bucket.end() && abs(nums[i] - bucket[bIdx - 1]) <= vDiff)
                return true;

            if (bucket.find(bIdx + 1) != bucket.end() && abs(nums[i] - bucket[bIdx + 1]) <= vDiff)
                return true;

            bucket[bIdx] = nums[i];
            if (i >= iDiff) {
                // Delete the farest left number from bucket
                bucket.erase(nums[i-iDiff]/_vDiff);
            }
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate_Set(vector<int>& nums, int indexDiff, int valueDiff) {
        std::set<int> window;
        for (int i = nums.size()-1; i>=0; --i)
        {
            auto& num = nums[i];
            auto [it, inserted] = window.insert(num);
            if (!inserted) // duplicated element
                return true;

            auto next = std::next(it);
            if (next != window.end() && *next - num <= valueDiff)
                return true;
            
            if (it != window.begin() && num - *std::prev(it) <= valueDiff)
                return true;

            if (window.size() > indexDiff)
            {
                window.erase(nums[i+indexDiff]);
            }
        }

        return false;
    }
};
