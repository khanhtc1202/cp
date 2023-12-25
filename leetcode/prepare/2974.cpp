/*
https://leetcode.com/problems/minimum-number-game/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i=i+2) {
            ans[i] = nums[i+1];
            ans[i+1] = nums[i];
        }
        return ans;
    }
};
