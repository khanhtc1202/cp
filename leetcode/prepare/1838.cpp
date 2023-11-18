/*
https://leetcode.com/problems/frequency-of-the-most-frequent-element/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = 0;
        long long sum = 0;
        for (int r = 0; r < nums.size(); ++r) {
            long long x = nums[r];
            sum += x;
            while ((r-l+1)*x - sum > k) {
                sum -= nums[l++];
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
