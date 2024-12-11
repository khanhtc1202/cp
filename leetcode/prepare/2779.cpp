/*
https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int r = 0, ans = 0;
        int cond = 2*k;
        for (int l = 0; l < nums.size(); ++l) {
            while (r < nums.size() && nums[r] - nums[l] <= cond) {
                r++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
