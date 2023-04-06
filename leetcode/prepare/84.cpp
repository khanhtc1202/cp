/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> l(n), r(n);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            l[i] = stk.empty() ? 0 : stk.back() + 1;
            stk.push_back(i);
        }

        stk = {};
        for (int i = n-1; i > -1; i--) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            r[i] = stk.empty() ? n-1 : stk.back() - 1;
            stk.push_back(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (r[i] - l[i] + 1));
        }
        return res;
    }
};
