/*
https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    //Use binary search to find number of nums[i]>=x
    inline int f(int x, vector<int>& nums){
        int i=lower_bound(nums.begin(), nums.end(), x)-nums.begin();
        return n-i;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        int l = 0, r = n, m;
        // Binary search in range [0, n]
        while (l <= r) {
            m = (l+r)/2;
            int cnt = f(m, nums);
            if (cnt == m) return m;
            else if (cnt > m) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};
