/*
https://leetcode.com/problems/non-decreasing-subsequences/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = nums.size();

        function<void(int)> backtrack = [&](int idx) -> void {
            if (tmp.size() > 1) {
                ans.push_back(tmp);
            }

            unordered_set<int> seen;

            for (int i = idx; i < n; i++) {
                if (!tmp.empty() && tmp.back() > nums[i]) continue;

                if (seen.find(nums[i]) != seen.end()) continue;

                tmp.push_back(nums[i]);
                backtrack(i+1);
                tmp.pop_back();

                seen.insert(nums[i]);
            }
        };

        backtrack(0);
        return ans;
    }
};
