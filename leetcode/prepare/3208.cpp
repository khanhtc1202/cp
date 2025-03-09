/*
https://leetcode.com/problems/alternating-groups-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0, n = colors.size();
        for (int l = 0, r = 1; l < n && r < 2*n; ++r) {
            if (colors[r%n] == colors[(r-1)%n]) {
                l = r%n;
            }
            else if (r - l + 1 == k) {
                ++ans;
                ++l;
            }
        }
        return ans;
    }
};
