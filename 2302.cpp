/*
https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0;
        long long ans = 0, sum = 0, cnt = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            ++cnt;
            while (sum * cnt >= k) {
                sum -= nums[left];
                ++left;
                --cnt;
            }
            ans += cnt;
        }
        return ans;
    }
};
