/*
https://leetcode.com/problems/car-pooling/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> timeline;
        for (auto trip: trips) {
            timeline[trip[1]] += trip[0];
            timeline[trip[2]] -= trip[0];
        }

        int used = 0;
        for (auto it: timeline) {
            used += it.second;
            if (used > capacity) return false;
        }
        return true;
    }
};
