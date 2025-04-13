/*
https://leetcode.com/problems/count-good-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int mod = 1e9+7;
public:
    int countGoodNumbers(long long n) {
        // use fast exponentiation to calculate x^y % mod
        auto expo = [](int x, long long y) -> int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };

        // {0,2,4,6,8} for even with (n+1)/2 indices
        // {2,3,5,7} for odd with (n)/2 indices
        return (long long)expo(5, (n + 1) / 2) * expo(4, n / 2) % mod;
    }
};
