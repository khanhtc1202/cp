/*
https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> stk;
        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            if (stk.empty() || prices[stk.back()] < prices[i]) {
                stk.push_back(i);
            } else {
                while (!stk.empty() && prices[stk.back()] >= prices[i]) {
                    prices[stk.back()] -= prices[i];
                    stk.pop_back();
                }
                stk.push_back(i);
            }
        }
        return prices;
    }
};
