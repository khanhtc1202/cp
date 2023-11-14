/*
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ll[26] = {[0 ... 25] = INT_MAX};
        int rr[26] = {};

        for (int i = 0; i < s.size(); ++i) {
            ll[s[i] - 'a'] = min(ll[s[i]-'a'], i);
            rr[s[i] - 'a'] = i;
        }

        int res = 0;
        for (int i = 0; i < 26; ++i) {
            // Found pair of index which s[i] == s[j]
            if (ll[i] < rr[i]) {
                // Add the number of diff char in between {i, j}
                res += unordered_set<char>(s.begin()+ll[i]+1, s.begin()+rr[i]).size();
            }
        }
        return res;
    }
};
