/*
https://leetcode.com/problems/delete-node-in-a-bst/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        // Have one leg
        if (!root->left) {
            return root->right;
        }
        if (!root->right) {
            return root->left;
        }

        // Have both legs
        TreeNode* node = root->right;
        while (node->left) {
            node = node->left;
        }
        // Now node is smallest of right subtree
        node->left = root->left;
        // Remove key
        root = root->right;
        return root;
    }
};
