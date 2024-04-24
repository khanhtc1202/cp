/*
https://leetcode.com/problems/n-th-tribonacci-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n < 2)
            return n;
        if (n == 2)
            return 1;
        int p2 = 1, p1 = 1, p0 = 0;
        int ans = 0;
        for (int i = 3; i <= n; i++) {
            ans = p0 + p1 + p2;
            p0 = p1; p1 = p2; p2 = ans;
        }
        return ans;
    }
};
