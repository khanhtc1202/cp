/*
https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto x: nums) {
            int cnt = 0;
            while (x) {
                ++cnt;
                x /= 10;
            }
            if (cnt % 2 == 0) ++ans;
        }
        return ans;
    }
};
