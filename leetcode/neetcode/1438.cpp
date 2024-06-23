/*
https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int ans = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while(!maxd.empty() && nums[i] >= nums[maxd.back()]) maxd.pop_back();
            while(!mind.empty() && nums[i] <= nums[mind.back()]) mind.pop_back();
            
            maxd.push_back(i); mind.push_back(i);
            
            while (nums[maxd.front()] - nums[mind.front()] > limit) {
                j++;
                while (maxd.front() < j) maxd.pop_front();
                while (mind.front() < j) mind.pop_front();
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
