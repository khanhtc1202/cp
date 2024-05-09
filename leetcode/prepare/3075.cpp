/*
https://leetcode.com/problems/maximize-happiness-of-selected-children/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
        int deb = 0, i = 0;
        while (k-- > 0)
            ans += max(happiness[i++] - deb++, 0);
        return ans;
    }
};
