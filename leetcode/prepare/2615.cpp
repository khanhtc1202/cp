/*
https://leetcode.com/problems/sum-of-distances/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> cnt;
        for (int i = 0; i < n; ++i) cnt[nums[i]].push_back(i);
        for (auto& [num, v]: cnt) {
            long long leftSum = 0, rightSum = 0;
            for (auto i: v) rightSum += i;
            for (int i = 0; i < v.size(); ++i) {
                rightSum -= v[i];
                leftSum += v[i];
                ans[v[i]] = rightSum - leftSum + (2LL * (i + 1) - v.size()) * v[i];
            }
        }
        return ans;
    }
};
