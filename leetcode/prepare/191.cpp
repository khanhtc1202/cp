#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // count bit one by one and check whether the current last bit is 1.
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n > 0) {
            if ((n&1) > 0)
                cnt++;
            n = n>>1; // n /= 2 means shift all bit to the right once.
        }
        return cnt;
    }

    // clear only most right bit which is 1 for each loop (much faster compare to shift one by one).
    int optimizedHammingWeight(uint32_t n) {
        int cnt = 0;
        while (n > 0) {
            cnt++;
            n &= (n-1); // make last bit 1 (the right most) to 0.
        }
        return cnt;
    }
};
