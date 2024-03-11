/*
https://leetcode.com/problems/custom-sort-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        for (char c: s) ++freq[c-'a'];
        string ans = "";
        for (char c: order) {
            while (freq[c-'a']-- > 0) ans += c;
        }
        for (int i = 0; i < 26; ++i) {
            while (freq[i]-- > 0) ans += (i+'a');
        }
        return ans;
    }
};
