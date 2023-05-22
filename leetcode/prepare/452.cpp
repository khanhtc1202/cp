/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> tmp;
        tmp.push_back(points[0]);
        for (int i = 1; i < points.size(); i++) {
            if (tmp.back()[1] < points[i][0]) {
                tmp.push_back(points[i]);
            } else {
                int l = max(tmp.back()[0], points[i][0]);
                int r = min(tmp.back()[1], points[i][1]);
                tmp.pop_back();
                tmp.push_back({l, r});
            }
        }
        return tmp.size();
    }
};
