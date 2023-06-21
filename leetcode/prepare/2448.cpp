/*
https://leetcode.com/problems/minimum-cost-to-make-array-equal/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> elements(n);
        for (int i = 0; i < n; i++) {
            elements[i] = make_pair(nums[i], cost[i]);
        }
        sort(elements.begin(), elements.end());

        vector<long long> prefixCost(n, 0);
        prefixCost[0] = elements[0].second;
        for (int i = 1; i < n; i++) {
            prefixCost[i] += prefixCost[i-1] + elements[i].second;
        }

        long long totalCost = 0;
        for (int i = 1; i < n; i++) {
            totalCost += 1l * elements[i].second * (elements[i].first - elements[0].first);
        }

        long long ans = totalCost;
        for (int i = 1; i < n; i++) {
            int gap = elements[i].first - elements[i-1].first;

            totalCost += prefixCost[i-1] * gap;
            totalCost -= (prefixCost[n-1] - prefixCost[i-1]) * gap;

            ans = min(ans, totalCost);
        }

        return ans;
    }
};
