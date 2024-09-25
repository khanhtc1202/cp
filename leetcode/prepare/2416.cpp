/*
Problem desc: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int cnt = 0;
    TrieNode* next[26] = {};
};

class Solution {
    TrieNode root;
public:
    void insert(string word) {
        auto node = &root;
        for (char c: word) {
            // New prefix
            if (!node->next[c-'a']) {
                node->next[c-'a'] = new TrieNode();
            }
            // Current prefix count
            node->next[c-'a']->cnt++;
            node = node->next[c-'a'];
        }
    }

    int count(string s) {
        auto node = &root;
        int ans = 0;
        for (char c: s) {
            ans += node->next[c-'a']->cnt;
            node = node->next[c-'a'];
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int N = words.size();
        for (int i = 0; i < N; ++i) {
            insert(words[i]);
        }
        vector<int> scores(N, 0);
        for (int i = 0; i < N; ++i) {
            scores[i] = count(words[i]);
        }
        return scores;
    }
};
