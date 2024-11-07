/*
https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 24; ++i) {
            int cnt = 0;
            for (auto x: candidates) {
                if ((x & (1 << i)) != 0) { // If i-th bit of x is set
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
