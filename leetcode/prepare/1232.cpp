/*
https://leetcode.com/problems/check-if-it-is-a-straight-line/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n < 3) return true;

        auto getXDiff = [&](int a, int b) -> int {
            return coordinates[a][0] - coordinates[b][0];
        };
        auto getYDiff = [&](int a, int b) -> int {
            return coordinates[a][1] - coordinates[b][1];
        };

        int deltaX = getXDiff(1, 0);
        int deltaY = getYDiff(1, 0);
        
        for (int i = 2; i < n; i++) {
            if (deltaY * getXDiff(i, 0) != deltaX * getYDiff(i, 0))
                return false;
        }
        return true;
    }
};
