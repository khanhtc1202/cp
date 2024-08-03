/*
https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1001] = {0};
        for (auto x: target) {
            freq[x]++;
        }
        for (auto x: arr) {
            if (--freq[x] < 0) return false;
        }
        return true;
    }
};
