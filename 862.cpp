/*
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSums(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSums[i] = prefixSums[i-1] + nums[i-1];
        }

        deque<int> candidateIndices;
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            while (!candidateIndices.empty() && prefixSums[i] - prefixSums[candidateIndices.front()] >= k) {
                ans = min(ans, i - candidateIndices.front());
                candidateIndices.pop_front();
            }

            while (!candidateIndices.empty() && prefixSums[i] <= prefixSums[candidateIndices.back()]) {
                candidateIndices.pop_back();
            }

            candidateIndices.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
