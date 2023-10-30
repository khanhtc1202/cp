/*
https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Number of bit 1
    int hammingWeight(int x) {
        int wt = 0;
        while (x > 0)
            x &= (x-1), ++wt;
        return wt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> B(32);
        for (auto& x: arr)
            B[hammingWeight(x)].push_back(x);
        for (auto& b: B)
            sort(b.begin(), b.end());

        int cnt = 0;
        for (int i = 0; i < 32; ++i)
            for (auto& x: B[i])
                arr[cnt++] = x;

        return arr;
    }
};
