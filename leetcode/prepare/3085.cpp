/*
https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> cnt;
        for (auto &c: word) cnt[c]++;
        int ans = word.size();
        for (auto &[_, x]: cnt) {
            int del = 0;
            for (auto &[_, y]: cnt) {
                if (x > y) {
                    del += y;
                } else if (y > x+k) {
                    del += y - (x + k);
                }
            }
            ans = min(ans, del);
        }
        return ans;
    }
};
