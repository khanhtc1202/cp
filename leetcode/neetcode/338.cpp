/*
https://leetcode.com/problems/counting-bits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(nlogn)
    vector<int> countBits(int n) {
        auto countOne = [](int n) -> int {
            int cnt = 0;
            while (n > 0) {
                if (n&1) cnt++;
                n >>= 1;
            }
            return cnt;
        };

        vector<int> res(n+1); res[0] = 0;
        for (int i = 1; i <= n; i++)
            res[i] = countOne(i);
        return res;
    }

    // O(n)
    vector<int> countBitsOpt(int n) {
        vector<int> res(n+1); res[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i%2) res[i] = res[i/2];
            else res[i] = 1 + res[i/2];
        }
        return res;
    }

    // O(n) beautiful sol: use x & (x-1) to set the last bit 1 to 0.
    vector<int> countBitsBeauty(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; i++)
            res[i] = res[i & (i-1)] + 1;
        return res;
    }
};
