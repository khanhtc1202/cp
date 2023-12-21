/*
https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> xs(n);
        for (int i = 0; i < n; ++i)
            xs[i] = points[i][0];

        sort(xs.begin(), xs.end());
        int ans = 0;
        for (int i = 1; i < n; ++i)
            ans = max(ans, xs[i] - xs[i-1]);

        return ans;
    }
};
