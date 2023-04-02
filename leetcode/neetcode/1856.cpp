/*
https://leetcode.com/problems/maximum-subarray-min-product/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = (prefix[i-1] + nums[i]);

        vector<int> L(n); L[0] = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            L[i] = stk.empty() ? 0 : stk.top() + 1;
            stk.push(i);
        }

        vector<int> R(n); R[n-1] = n-1;
        stk = stack<int> ();
        for (int i = n-1; i > -1; i--) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            R[i] = stk.empty() ? n-1 : stk.top() - 1;
            stk.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, nums[i] * (prefix[R[i]] - prefix[L[i]] + nums[L[i]]));
        }
        int mod = 1e9 + 7;
        return res % mod;
    }
};
