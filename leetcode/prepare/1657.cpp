/*
https://leetcode.com/problems/determine-if-two-strings-are-close/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> cnt1(26, 0), cnt2(26, 0);
        vector<int> char1(26, 0), char2(26, 0);
        for (int i = 0; i < word1.size(); ++i) {
            ++cnt1[word1[i]-'a'];
            ++cnt2[word2[i]-'a'];
            char1[word1[i]-'a'] = 1;
            char2[word2[i]-'a'] = 1;
        }
        if (char1 != char2) return false;

        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};
