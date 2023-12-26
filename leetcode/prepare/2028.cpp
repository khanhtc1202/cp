/*
https://leetcode.com/problems/find-missing-observations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (n + rolls.size());
        for (auto v: rolls) sum -= v;

        // Fill n buckets which total of sum.
        vector<int> ans(n);
        for (int fill = n; fill > 0; --fill) {
            int avg = sum / fill;
            // No way to fill
            if (avg > 6 || avg < 1) return {};
            // Fill the current bucket
            ans[n-fill] = avg;
            // Update sum
            sum -= avg;
        }
        return ans;
    }
};
