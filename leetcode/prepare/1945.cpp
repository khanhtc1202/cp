/*
https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for (auto c: s) {
            int d = c - 'a' + 1;
            if (d > 9) {
                ans += ((d / 10) + (d % 10));
            } else ans += d;
        }
        k = k - 1;
        while (k > 0) {
            int tmp = 0;
            while (ans > 0) {
                tmp += (ans % 10);
                ans /= 10;
            }
            ans = tmp;
            --k;
        }
        return ans;
    }
};
