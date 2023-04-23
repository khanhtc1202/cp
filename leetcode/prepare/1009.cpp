/*
https://leetcode.com/problems/complement-of-base-10-integer/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int remain = n, bit = 1;
        while (remain != 0) {
            n = n ^ bit;
            bit = bit << 1;
            remain = remain >> 1;
        }
        return n;
    }
};
