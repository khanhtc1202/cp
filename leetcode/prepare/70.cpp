/*
https://leetcode.com/problems/climbing-stairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = prev1 + prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};
