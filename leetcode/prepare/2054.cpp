/*
https://leetcode.com/problems/two-best-non-overlapping-events/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // min heap of {end, value}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        sort(events.begin(), events.end());
        int maxVal = 0, maxSum = 0;

        for (auto& e: events) {
            // Check all previous events which end before current event start
            // to find whether any new "valid" events that its value greater than maxVal
            // or not, if not, maxVal - most valuable valid previous event will be used.
            while (!minHeap.empty() && minHeap.top().first < e[0]) {
                maxVal = max(maxVal, minHeap.top().second);
                minHeap.pop();
            }
            maxSum = max(maxSum, maxVal + e[2]);
            minHeap.push({e[1], e[2]});
        }
        return maxSum;
    }
};
