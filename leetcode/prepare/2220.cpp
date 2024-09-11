/*
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while (start > 0 || goal > 0) {
            if ((start & 1) != (goal & 1)) {
                cnt++;
            }
            // shift right and move to next right-most bit
            start >>= 1;
            goal >>= 1;
        }
        return cnt;
    }

    // Built-in function
    int minBitFlips_Ops(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
