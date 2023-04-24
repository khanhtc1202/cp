/*
https://leetcode.com/problems/max-points-on-a-line/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 1;

        int ans = 2;
        unordered_map<double, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt = {};
            for (int j = 0; j < n; j++) {
                if (i != j)
                    cnt[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
            }
            for (auto [h, count]: cnt) {
                ans = max(ans, count+1);
            }
        }
        return ans;
    }
};
