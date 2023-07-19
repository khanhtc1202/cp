/*
https://leetcode.com/problems/merge-intervals/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOverlap(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] >= v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> out;

        out.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlap(out.back(), intervals[i])) {
                out.back()[1] = max(out.back()[1], intervals[i][1]);
            } else {
                out.push_back(intervals[i]);
            }
        }
        return out;
    }
};
