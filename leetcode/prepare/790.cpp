#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9+7;

    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int i3 = 0;
        int i2 = 1;
        int i1 = 2;
        int out = 0;
        for (int i = 3; i < n+1; i++) {
            out = ((2*i1 % mod) + i3) % mod;
            i3 = i2;
            i2 = i1;
            i1 = out;
        }
        return out;
    }
};
