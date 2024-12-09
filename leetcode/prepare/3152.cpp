/*
https://leetcode.com/problems/special-array-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> prefix(nums.size(), 0); // contains special subarray index up to curr i
        prefix[0] = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == nums[i-1] % 2) {
                prefix[i] = prefix[i-1] + 1; // new subarray
            } else {
                prefix[i] = prefix[i-1];
            }
        }

        for (int i = 0; i < queries.size(); ++i) {
            vector<int> q = queries[i];
            int s = q[0], e = q[1];
            ans[i] = (prefix[s] == prefix[e]);
        }
        return ans;
    }
};
