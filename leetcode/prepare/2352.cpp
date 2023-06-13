/*
https://leetcode.com/problems/equal-row-and-column-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> r_memo;
        for (int i = 0; i < n; i++) {
            string key = "";
            for (int j = 0; j < n; j++) {
                key += (to_string(grid[i][j]) + "_");
            }
            r_memo[key]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            string key = "";
            for (int j = 0; j < n; j++) {
                key += (to_string(grid[j][i]) + "_");
            }
            ans += r_memo[key];
        }
        return ans;
    }
};
