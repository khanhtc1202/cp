/*
https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int times = piles.size() / 3;
        int ans = 0;
        for (int i = piles.size() - 2; times--; i=i-2) {
            ans += piles[i];
        }
        return ans;
    }
};
