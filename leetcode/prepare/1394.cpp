/*
https://leetcode.com/problems/find-lucky-integer-in-an-array
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501] = {0}, maxX = 0;
        for (int x: arr) {
            freq[x]++;
            maxX = max(maxX, x);
        }
        for (int x = maxX; x >= 1; --x) {
            if (freq[x] == x) return x;
        }
        return -1;
    }
};
