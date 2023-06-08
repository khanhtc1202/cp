/*
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int currPosNeg = n - 1;
        int ans = 0;
        for (auto row: grid) {
            while (currPosNeg >= 0 && row[currPosNeg] < 0) {
                currPosNeg--;
            }
            ans += (n - (currPosNeg+1));
        }

        return ans;
    }
};
