#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int x;
        for (int i = 0; i < 32; i++) {
            x = (n>>i)&1;
            res = (res<<i)+x;
        }
        return res;
    }
};
