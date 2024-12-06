/*
https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> b(banned.begin(), banned.end());
        int sum = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (b.count(i)) continue;
            sum += i;
            if (sum > maxSum) return ans;
            ans++;
        }
        return ans;
    }
};
