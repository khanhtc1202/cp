/*
https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> levels; // Contains last "current" node of each level
        int index = 0, n = traversal.size();

        while (index < n) {
            int dept = 0;
            while (index < n && traversal[index] == '-') {
                index++;
                dept++;
            }
            // get node value
            int value = 0;
            while (index < n && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index]-'0');
                index++;
            }
            // make node
            TreeNode* node = new TreeNode(value);

            // Update last "current" node of level
            if (dept < levels.size()) {
                levels[dept] = node;
            } else levels.push_back(node);

            // Find parent node
            if (dept > 0) {
                // parent always the last current node of level
                TreeNode* parent = levels[dept-1];
                if (parent->left == nullptr) {
                    parent->left = node;
                } else parent->right = node;
            }
        }
        return levels[0]; // root always the only node at level 0
    }
};
