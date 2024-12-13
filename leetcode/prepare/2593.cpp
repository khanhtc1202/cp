/*
https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<pair<int,int>> sorted(n);
        for (int i = 0; i < n; ++i) {
            sorted[i] = make_pair(nums[i], i);
        }
        sort(sorted.begin(), sorted.end());
        vector<bool> marked(n, false);
        for (int i = 0; i < n; ++i) {
            auto [x, idx] = sorted[i];
            if (!marked[idx]) {
                ans += x;
                marked[idx] = true;
                if (idx-1 >= 0) marked[idx-1] = true;
                if (idx+1 < n) marked[idx+1] = true; 
            }
        }
        return ans;
    }
};
