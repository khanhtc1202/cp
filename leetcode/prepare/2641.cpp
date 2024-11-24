/*
https://leetcode.com/problems/cousins-in-binary-tree-ii/
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) return root;

        queue<TreeNode*> q;
        q.push(root);
        int currLevelSum = root->val;
        while (!q.empty()) {
            int sz = q.size();
            int nextLevelSum = 0;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                node->val = currLevelSum - node->val;
                
                // cal sibling sum
                int siblingSum = (node->left != nullptr ? node->left->val : 0) +
                                 (node->right != nullptr ? node->right->val : 0);
                
                if (node->left != nullptr) {
                    nextLevelSum += node->left->val;
                    node->left->val = siblingSum;
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    nextLevelSum += node->right->val;
                    node->right->val = siblingSum;
                    q.push(node->right);
                }
            }
            currLevelSum = nextLevelSum;
        }
        return root;
    }
};
