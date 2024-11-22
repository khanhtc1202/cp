/*
https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> pattern;
        for (auto& row: matrix) {
            string patternBuilder = "";
            // Build pattern of the row based on the first element
            // eg. [0,1] and [1,0] is equal since they can be converted to [T, F] pattern
            for (int col = 0; col < row.size(); ++col) {
                if (row[0] == row[col]) {
                    patternBuilder += "T";
                } else patternBuilder += "F";
            }
            pattern[patternBuilder]++;
        }
        int ans = 0;
        for (auto& x: pattern) {
            // The most frequency pattern is the maximum possible row
            // that can be converted to the same value;
            ans = max(ans, x.second);
        }
        return ans;
    }
};
