/*
https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int rc = rectangles.size();
        vector<vector<int>> vertical(rc);
        vector<vector<int>> horizontial(rc);

        for (int i = 0; i < rc; ++i) {
            auto& r = rectangles[i];
            vertical[i] = {r[0], r[2]};
            horizontial[i] = {r[1], r[3]};
        }

        sort(vertical.begin(), vertical.end());
        sort(horizontial.begin(), horizontial.end());

        int cnt = 0, lastEnd = vertical[0][1];
        for (int i = 1; i < rc; ++i) {
            int start = vertical[i][0], end = vertical[i][1];
            if (start >= lastEnd) {
                cnt++;
            }
            lastEnd = max(lastEnd, end);
        }

        if (cnt >= 2) return true;

        cnt = 0, lastEnd = horizontial[0][1];
        for (int i = 1; i < rc; ++i) {
            int start = horizontial[i][0], end = horizontial[i][1];
            if (start >= lastEnd) {
                cnt++;
            }
            lastEnd = max(lastEnd, end);
        }

        return cnt >= 2;
    }
};
