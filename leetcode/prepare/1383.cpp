/*
https://leetcode.com/problems/maximum-performance-of-a-team/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> source(n);
        for (int i = 0; i < n; i++) source.push_back({efficiency[i], speed[i]});
        sort(source.begin(), source.end(), greater<pair<int, int>>());
        long long ans = 0; priority_queue<int, vector<int>, greater<int>> heap;
        long long curr_sum = 0;
        for (int i = 0; i < n; i++) {
            // Build best k speed for each curr min (at i)
            if (i < k) {
                heap.push(source[i].second);
                curr_sum += source[i].second;
            } else {
                if (heap.top() < source[i].second) {
                    curr_sum = curr_sum - heap.top() + source[i].second;
                    heap.pop();
                    heap.push(source[i].second);
                }
            }

            ans = max(ans, curr_sum * source[i].first);
        }
        return ans % int(1e9 + 7);
    }
};
