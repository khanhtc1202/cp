/*
https://leetcode.com/problems/minimum-interval-to-include-each-query/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        int n = queries.size(); int m = intervals.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bucket;
        int i_idx = 0;
        vector<int> ans(n);
        for (auto i: idx) {
            while (i_idx < m && intervals[i_idx][0] <= queries[i]) {
                bucket.push({intervals[i_idx][1] - intervals[i_idx][0] + 1, intervals[i_idx][1]});
                i_idx++;
            }
            while (!bucket.empty() && bucket.top().second < queries[i]) {
                bucket.pop();
            }
            ans[i] = bucket.empty() ? -1 : bucket.top().first;
        }
        return ans;
    }
};
