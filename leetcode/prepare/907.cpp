/*
https://leetcode.com/problems/sum-of-subarray-minimums/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.back()] > arr[i])
                stk.pop_back();

            left[i] = stk.empty() ? 0 : stk.back() + 1;
            stk.push_back(i);
        }

        stk = {};
        int ans = 0;
        for (int i = n-1; i > -1; --i) {
            while (!stk.empty() && arr[stk.back()] >= arr[i])
                stk.pop_back();

            int right = stk.empty() ? n - 1 : stk.back() - 1;
            ans += 1ll * (right - i + 1) * (i - left[i] + 1) * arr[i] % MOD;
            ans %= MOD;

            stk.push_back(i);
        }
        return ans;
    }

    int sumSubarrayMinsOpt(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> stk;

        for (int i = 0; i <= n; ++i) {
            while (!stk.empty() && (i == n || arr[stk.back()] >= arr[i])) {
                int mid = stk.back(); stk.pop_back();
                int left = stk.empty() ? -1 : stk.back();
                ans += 1ll * arr[mid] * (mid - left) * (i - mid) % MOD;
                ans %= MOD;
            }
            stk.push_back(i);
        }

        return ans;
    }
};
