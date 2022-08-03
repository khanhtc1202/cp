#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<int> dp(1<<n); dp[0] = 1;

        for (int mask = 0; mask < 1<<n; mask++) {
            // count the current of set to 1 bits of mask => the next index will be sz+1;
            int sz = __builtin_popcount(mask);
            for (int i = 0; i < n; i++) {
                if (!(mask >> i & 1)) {
                    // calculate the next index to store in dp, which is
                    // the current mask with the bit i is set to 1 from 0.
                    int nxt = mask | (1<<i);
                    // check the condition to know whether we should choose this
                    // number to build the permutation
                    // if the condition passed, which means use this number will build
                    // up a permutation of size (sz+1) that satify the condition.
                    if ((i+1)%(sz+1) == 0 || (sz+1)%(i+1) == 0)
                        dp[nxt] += dp[mask];
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
