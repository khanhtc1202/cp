/*
https://leetcode.com/problems/three-consecutive-odds/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (auto& x: arr) {
            if (x % 2) ++cnt;
            else cnt = 0;
            if (cnt == 3) return true;
        }
        return false;
    }
};
