/*
https://leetcode.com/problems/h-index/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n+1, 0);

        for (auto c: citations) {
            if (c >= n) bucket[n]++;
            else bucket[c]++;
        }

        int cnt = 0;
        for (int i = n; i >= 0; --i) {
            cnt += bucket[i];
            if (cnt >= i) return i;
        }
        return 0;
    }
};
