/*
https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> added(26, 0);

        for (char c: s)
            freq[c-'a']++;

        string ans = "";
        for (char c: s) {
            freq[c-'a']--;
            if (added[c-'a']) continue;
            while (ans != "" && c < ans.back() && freq[ans.back()-'a'] > 0) {
                added[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            added[c-'a'] = true;
        }
        return ans;
    }
};
