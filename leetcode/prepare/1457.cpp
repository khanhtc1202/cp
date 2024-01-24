/*
https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<pair<TreeNode*, bitset<10>>> stk;
        stk.emplace_back(root, 0);
        int ans = 0;
        while (!stk.empty()) {
            auto [node, parity] = stk.back();
            stk.pop_back();
            int x = node->val;
            // Count node val
            parity.flip(x);
            // If node is leaf, check pseudo-palindrome
            if (!node->left && !node->right) {
                if (parity.count() < 2) ans++;
                continue;
            }
            // Keep traveling
            if (node->left) stk.emplace_back(node->left, parity);
            if (node->right) stk.emplace_back(node->right, parity);
        }
        return ans;
    }
};
