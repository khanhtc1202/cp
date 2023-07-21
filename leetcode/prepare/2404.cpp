/*
https://leetcode.com/problems/most-frequent-even-element/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& A) {
        unordered_map<int, int> cnt;
        for (int n : A) {
            if (n % 2 == 0) cnt[n]++;
        }
        int maxFreq = 0, ans = -1;
        for (auto &[n, c] : cnt) {
            if (c > maxFreq) {
                ans = n;
                maxFreq = c;
            } else if (c == maxFreq && n < ans) ans = n;
        }
        return ans;
    }
};
