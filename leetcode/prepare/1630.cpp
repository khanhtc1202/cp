/*
https://leetcode.com/problems/arithmetic-subarrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = isArithmetic(nums, l[i], r[i]);
        }
        return ans;
    }

    bool isArithmetic(vector<int>& nums, int ll, int rr) {
        auto [minN, maxN] = minmax_element(nums.begin()+ll, nums.begin()+(rr+1));
        int diff = *maxN - *minN;
        // All numbers are equal or less than 3 number encounted
        if (diff == 0 || rr - ll < 2) return true;

        auto [d, r] = div(diff, rr-ll);
        // If the diff can not dividable to the number in between
        if (r != 0) return false;

        vector<int> count(rr-ll+1, 0);
        for (int i = ll; i <= rr; ++i) {
            int x = nums[i] - *minN;
            // Diff between current number with the minN
            // is not dividable to the consecutive diff
            if (x % d != 0) return false;

            int idx = x/d;
            // The was the same number encounted
            if (count[idx]) return false;
            else count[idx] = 1;
        }
        return true;
    }
};
