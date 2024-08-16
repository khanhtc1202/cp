/*
https://leetcode.com/problems/maximum-distance-in-arrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int xMin = 1e5, xMax = -1e5;
        int diff = 0;
        for (auto a: arrays) {
            int a0 = a[0], aN = a.back();
            diff = max({diff, aN - xMin, xMax - a0});
            xMin = min(xMin, a0);
            xMax = max(xMax, aN);
        }
        return diff;
    }
};
