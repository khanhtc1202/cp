/*
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool eow;
    vector<TrieNode*> next;

    TrieNode(): eow(false), next(26) {}
};

class Trie {
TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (auto rune: word) {
            int idx = rune - 'a';
            if (curr->next[idx] == nullptr)
                curr->next[idx] = new TrieNode();
            curr = curr->next[idx];
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (auto rune: word) {
            int idx = rune - 'a';
            curr = curr->next[idx];
            if (curr == nullptr) return false;
        }
        return curr->eow;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto rune: prefix) {
            int idx = rune - 'a';
            curr = curr->next[idx];
            if (curr == nullptr) return false;
        }
        return true;
    }
};
