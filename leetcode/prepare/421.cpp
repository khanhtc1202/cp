/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    vector<int> toBit(int num) {
        vector<int> ans;
        for (int i = 30; i >= 0; i--) {
            ans.push_back(num >> i & 1);
        }
        return ans;
    }

    void insert(int num) {
        vector<int> bits = toBit(num);
        TrieNode* curr = root;
        for (auto bit: bits) {
            if (curr->child[bit] == nullptr) {
                curr->child[bit] = new TrieNode();
            }
            curr = curr->child[bit];
        }
    }

    int find(int num) {
        vector<int> bits = toBit(num);
        TrieNode* curr = root;
        int ans = 0;
        for (auto bit: bits) {
            if (curr->child[!bit] != nullptr) {
                ans = ans * 2 + 1;
                curr = curr->child[!bit];
            } else {
                ans = ans * 2;
                curr = curr->child[bit];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (auto num: nums) {
            trie.insert(num);
        }

        int ans = 0;
        for (auto num: nums) {
            ans = max(ans, trie.find(num));
        }
        return ans;
    }
};
