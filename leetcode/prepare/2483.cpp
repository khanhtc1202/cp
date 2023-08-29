/*
https://leetcode.com/problems/minimum-penalty-for-a-shop/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n+1, 0), postfix(n+1, 0);

        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i] + (customers[i] == 'N' ? 1 : 0);
            postfix[n-1-i] = postfix[n-i] + (customers[n-1-i] == 'Y' ? 1 : 0);
        }

        int ans = n, penalty = INT_MAX, tmp;
        for (int i = 0; i <= n; ++i) {
            tmp = prefix[i] + postfix[i];
            if (penalty > tmp)
                ans = i, penalty = tmp;
        }
        return ans;
    }
};
