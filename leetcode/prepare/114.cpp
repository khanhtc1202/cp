/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        function<TreeNode*(TreeNode*)> shift = [&] (TreeNode* node) -> TreeNode* {
            if (!node) return nullptr;

            if (!node->left && !node->right)
                return node;

            TreeNode* leftTail = shift(node->left);
            TreeNode* rightTail = shift(node->right);

            if (leftTail) {
                leftTail->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }

            return rightTail ? rightTail : leftTail;
        };

        shift(root);
    }
};
