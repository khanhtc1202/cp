/*
https://leetcode.com/problems/non-overlapping-intervals/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> prev = ans.back();
            if (prev[1] <= intervals[i][0]) {
                ans.push_back(intervals[i]);
                continue;
            }
            if (prev[1] < intervals[i][1]) {
                continue;
            } else {
                ans.pop_back();
                ans.push_back(intervals[i]);
            }
        }
        return intervals.size() - ans.size();
    }
};
