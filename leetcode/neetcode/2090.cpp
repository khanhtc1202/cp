/*
https://leetcode.com/problems/k-radius-subarray-averages/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        long sum = 0;
        int window_size = k+k+1, double_k = k+k;
        vector<int> ans(n, -1);

        for (int end = 0; end < n; ++end) {
            sum += nums[end];
            if (end >= double_k) {
                ans[start+k] = sum / window_size;
                sum -= nums[start++];
            }
        }
        return ans;
    }
};
