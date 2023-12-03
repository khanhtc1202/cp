/*
https://leetcode.com/problems/minimum-time-visiting-all-points/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int diffX, diffY;
        for (int i = 1; i < points.size(); ++i) {
            diffX = abs(points[i-1][0] - points[i][0]);
            diffY = abs(points[i-1][1] - points[i][1]);
            ans += max(diffX, diffY);
        }
        return ans;
    }
};
