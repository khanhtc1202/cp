/*
https://leetcode.com/problems/count-complete-subarrays-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_count = distinct.size();

        int right = 0, ans = 0, n = nums.size();
        unordered_map<int,int> cnt;
        for (int left = 0; left < n; ++left) {
            if (left > 0) {
                int del = nums[left-1];
                cnt[del]--;
                if (cnt[del] == 0) cnt.erase(del);
            }
            // expand right until the condition is sartified
            while (right < n && cnt.size() < distinct_count) {
                int add = nums[right];
                ++cnt[add];
                ++right;
            }
            // all subarray contains [left, right] will be added
            if (cnt.size() == distinct_count) {
                ans += (n - right + 1);
            }
        }
        return ans;
    }
};
