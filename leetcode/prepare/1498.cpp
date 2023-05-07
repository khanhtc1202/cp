/*
https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, mod = 1e9+7;
        int n = nums.size();
        int left = 0, right = n - 1;

        // Precompute the power or you will get TLE.
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2) % mod;
        }
        
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                (ans += power[right - left]) %= mod;
                left++;
            }
        }
        return ans;
    }
};
