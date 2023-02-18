/*
Problem desc: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNodeT {
    int score;
    vector<TreeNodeT*> nexts;

    TreeNodeT(): score(0), nexts(26) {}
};

struct Trie {
    TreeNodeT* root;

    Trie() {
        root = new TreeNodeT();
    }

    void addWord(string word) {
        TreeNodeT* curr = root;
        for (auto rune: word) {
            int idx = rune - 'a';
            if (curr->nexts[idx] == nullptr) {
                curr->nexts[idx] = new TreeNodeT();
            }
            curr = curr->nexts[idx];
            curr->score++;
        }
    }

    int scoreWord(string word) {
        TreeNodeT* curr = root;
        int total = 0;
        for (auto rune: word) {
            int idx = rune - 'a';
            curr = curr->nexts[idx];
            total += curr->score;
        }
        return total;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie tree;
        for (auto word: words) {
            tree.addWord(word);
        }
        vector<int> ans(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            ans[i] = tree.scoreWord(words[i]);
        }
        return ans;
    }
};
