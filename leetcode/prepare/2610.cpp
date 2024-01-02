/*
https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int freq[201] = {0};
        for (auto x: nums) {
            if (freq[x] == ans.size()) {
                ans.push_back({x});
            } else {
                ans[freq[x]].push_back(x);
            }
            freq[x]++;
        }
        return ans;
    }
};
