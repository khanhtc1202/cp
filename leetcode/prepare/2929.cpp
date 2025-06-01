/*
https://leetcode.com/problems/distribute-candies-among-children-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        int lim = min(limit, n);
        for (int i = 0; i <= lim; ++i) {
            if (n - i > 2 * limit) continue;
            ans += min(n-i, limit) - max(0, n - i - limit) + 1;
        }
        return ans;
    }
};
