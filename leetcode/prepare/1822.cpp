/*
https://leetcode.com/problems/sign-of-the-product-of-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (auto e: nums) {
            if (e == 0) return 0;
            ans *= (e > 0) ? 1 : -1;
        }
        return ans;
    }
};
