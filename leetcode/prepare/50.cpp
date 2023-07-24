/*
https://leetcode.com/problems/powx-n/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, long n) {
        if (n < 0) return 1 / myPow(x, -n);
        double ans = 1;
        while (n) {
            if (n & 1) ans *= x;
            n >>= 1;
            x *= x;
        }
        return ans;
    }
};
