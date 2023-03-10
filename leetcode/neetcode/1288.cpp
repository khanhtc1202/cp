/*
https://leetcode.com/problems/remove-covered-intervals/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return 1;

        sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2) {
            return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);
        });
        int mx = intervals[0][1], ans = n;
        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= mx) ans--;
            else mx = intervals[i][1];
        }
        return ans;
    }
};
