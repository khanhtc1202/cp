/*
https://leetcode.com/problems/count-elements-with-maximum-frequency/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int _max = 0, ans = 0;
        vector<int> freq(101, 0);
        for (auto x: nums) _max = max(_max, ++freq[x]);
        for (auto f: freq) if (f == _max) ans += f;
        return ans;
    }
};
