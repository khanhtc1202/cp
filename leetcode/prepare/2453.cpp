/*
https://leetcode.com/problems/destroy-sequential-targets/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, pair<int, int>> memo;
        int remainder, targets = INT_MIN;
        for (auto num: nums) {
            remainder = num % space;
            if (memo.find(remainder) == memo.end()) {
                memo[remainder] = make_pair(1, num);
            } else {
                memo[remainder] = make_pair(memo[remainder].first+1, min(memo[remainder].second, num));
            }
            targets = max(targets, memo[remainder].first);
        }

        int ans = INT_MAX;
        for (auto [k, v]: memo) {
            if (v.first == targets) {
                ans = min(ans, v.second);
            }
        }
        return ans;
    }
};
