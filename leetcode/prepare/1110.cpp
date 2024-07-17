/*
https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    TreeNode* travel(TreeNode* node, unordered_set<int>& toDel, vector<TreeNode*>& forest) {
        if (!node) return nullptr;

        node->left = travel(node->left, toDel, forest);
        node->right = travel(node->right, toDel, forest);

        if (toDel.count(node->val)) {
            if (node->left) forest.push_back(node->left);
            if (node->right) forest.push_back(node->right);
            // Delete
            delete node;
            return nullptr;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDel(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = travel(root, toDel, forest);
        if (root) forest.push_back(root);

        return forest;
    }
};
