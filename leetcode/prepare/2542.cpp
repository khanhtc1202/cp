/*
https://leetcode.com/problems/maximum-subsequence-score/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = {nums2[i], nums1[i]};
        }
        sort(nums.begin(), nums.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> heap;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            heap.push(nums[i].second);
            sum += nums[i].second;
        }

        long long ans = sum * nums[k-1].first;
        for (int i = k; i < n; i++) {
            sum += nums[i].second - heap.top();
            heap.pop();
            heap.push(nums[i].second);

            ans = max(ans, nums[i].first * sum);
        }
        return ans;
    }
};
