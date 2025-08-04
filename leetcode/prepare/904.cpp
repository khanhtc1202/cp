/*
https://leetcode.com/problems/fruit-into-baskets/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int n = fruits.size();
        int freq[100001] = {0};
        int ans = 0, cnt = 0, baskets = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            // add basket count as soon as we found new fruit
            if (++freq[fruits[r]] == 1) baskets++;
            cnt++; // increase counter as take a fruit of known type
            while (baskets > 2) {
                if (--freq[fruits[l]]==0) baskets--;
                ++l;
                --cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
