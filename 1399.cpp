/*
https://leetcode.com/problems/count-largest-group/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> hm;
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int k = 0, i0 = i;
            while (i0) {
                k += i0 % 10;
                i0 /= 10;
            }
            ++hm[k];
            maxValue = max(maxValue, hm[k]);
        }
        int ans = 0;
        for (auto& [_, v]: hm) {
            if (v == maxValue) {
                ++ans;
            }
        }
        return ans;
    }
};
