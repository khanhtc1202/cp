/*
https://leetcode.com/problems/binary-tree-upside-down/
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) {
            return root;
        }

        TreeNode* _root = upsideDownBinaryTree(root->left);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        left->left = right;
        left->right = root;

        root->left = nullptr;
        root->right = nullptr;

        return _root;
    }
};
