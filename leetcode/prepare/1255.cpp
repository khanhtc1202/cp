/*
https://leetcode.com/problems/maximum-score-words-formed-by-letters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int freq[26], subset[26], ans = 0;
    void backtrack(int idx, vector<string>& words, vector<int>& score) {
        if (idx == words.size()) {
            int sc = 0;
            for (int i = 0; i < 26; ++i) {
                if (subset[i] > freq[i]) return; // invalid char
                sc += score[i] * subset[i];
            }
            ans = max(ans, sc);
            return;
        }

        backtrack(idx+1, words, score);
        for (auto i : words[idx]) subset[i-'a']++;
        backtrack(idx+1, words, score);
        for (auto i : words[idx]) subset[i-'a']--;
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (auto i: letters) freq[i-'a']++;
        backtrack(0, words, score);
        return ans;
    }
};
