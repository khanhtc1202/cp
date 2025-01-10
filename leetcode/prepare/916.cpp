/*
https://leetcode.com/problems/word-subsets/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> dict(26, 0);
        for (string& s: words2) {
            vector<int> temp(26, 0);
            for (char c: s) {
                temp[c-'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                dict[i] = max(dict[i], temp[i]);
            }
        }

        vector<string> ans;
        for (string& s: words1) {
            vector<int> temp(26, 0);
            for (char c: s) {
                temp[c-'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                if (dict[i] > temp[i])
                    goto L;
            }
            ans.push_back(s);
L:
        }
        return ans;
    }
};
