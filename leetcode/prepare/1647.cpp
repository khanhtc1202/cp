/*
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        for (auto c: s)
            count[c-'a']++;

        unordered_map<int, int> hash;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            while (count[i] != 0 && hash.find(count[i]) != hash.end()) {
                count[i]--;
                ans++;
            }
            if (count[i] != 0)
                hash[count[i]] = i;
        }
        return ans;
    }

    int minDeletions_Opt(string s) {
        vector<int> count(26, 0);
        for (auto c: s)
            count[c-'a']++;

        unordered_set<int> memo;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            while (count[i] != 0 && memo.count(count[i]) != 0) {
                count[i]--;
                ans++;
            }
            if (count[i] != 0)
                memo.insert(count[i]);
        }
        return ans;
    }
};
