/*
https://leetcode.com/problems/finding-3-digit-even-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        int cntEven = 0;
        for (auto& x: digits) {
            freq[x]++;
            if (x%2 == 0) cntEven++;
        }
        if (cntEven == 0) return {};

        vector<int> ans;
        for (int x = 100; x < 999; x += 2) {
            auto tmp = freq;
            int x0 = x%10, x1 = (x/10)%10, x2 = x/100;
            if (tmp[x0]-- <= 0) continue;
            if (tmp[x1]-- <= 0) continue;
            if (tmp[x2]-- <= 0) continue;
            ans.push_back(x);
        }
        return ans;
    }
};
